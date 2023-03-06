#ifndef __ZMSG_H_INCLUDED__
#define __ZMSG_H_INCLUDED__

#include "zhelpers.hpp"

#include <vector>
#include <string>
#include <stdarg.h>

class zmsg {
public:
    zmsg() {
    }

   //  --------------------------------------------------------------------------
   //  Constructor, sets initial body
   zmsg(void const *body, size_t body_len) {
       body_set(body, body_len);
   }

   //  -------------------------------------------------------------------------
   //  Constructor, sets initial body and sends message to socket
   zmsg(void const *body, size_t body_len, zmq::socket_t &socket) {
       body_set(body, body_len);
       send(socket);
   }

   //  --------------------------------------------------------------------------
   //  Constructor, calls first receive automatically
   zmsg(zmq::socket_t &socket) {
       recv(socket);
   }

   //  --------------------------------------------------------------------------
   //  Copy Constructor, equivalent to zmsg_dup
   zmsg(zmsg &msg) {
       m_part_data.resize(msg.m_part_data.size());
       std::copy(msg.m_part_data.begin(), msg.m_part_data.end(), m_part_data.begin());
   }

   virtual ~zmsg() {
      clear();
   }

   //  --------------------------------------------------------------------------
   //  Erases all messages
   void clear() {
       m_part_data.clear();
   }

   void set_part(size_t part_nbr, std::vector<uint8_t> data) {
       if (part_nbr < m_part_data.size()) {
           m_part_data[part_nbr] = data;
       }
   }

   bool recv(zmq::socket_t & socket) {
      clear();
      while(1) {
         zmq::message_t message(0);
         try {
            if (!socket.recv(&message, 0)) {
               return false;
            }
         } catch (zmq::error_t error) {
            std::cout << "E: " << error.what() << std::endl;
            return false;
         }
         //std::cerr << "recv: \"" << (unsigned char*) message.data() << "\", size " << message.size() << std::endl;
         if (message.size() == 17 && ((unsigned char *)message.data())[0] == 0) {
            m_part_data.push_back(encode_uuid((unsigned char*) message.data()));
         }
         else {
            std::vector<uint8_t> tmp((uint8_t*)message.data(), (uint8_t*)message.data()+message.size());
            m_part_data.push_back(tmp);
         }
         if (!message.more()) {
            break;
         }
      }
      return true;
   }

   void send(zmq::socket_t & socket) {
       for (size_t part_nbr = 0; part_nbr < m_part_data.size(); part_nbr++) {
          zmq::message_t message;
          std::vector<uint8_t> data = m_part_data[part_nbr];
          if (data.size() == 33 && data [0] == '@') {
             unsigned char * uuidbin = decode_uuid (data.data());
             message.rebuild(17);
             memcpy(message.data(), uuidbin, 17);
             delete uuidbin;
          }
          else {
             message.rebuild(data.size());
             memcpy(message.data(), data.data(), data.size());
          }
          try {
             socket.send(message, part_nbr < m_part_data.size() - 1 ? ZMQ_SNDMORE : 0);
          } catch (zmq::error_t error) {
             assert(error.num()!=0);
          }
       }
       clear();
   }

   size_t parts() {
      return m_part_data.size();
   }

   void body_set(const void *body, size_t body_len) {
      if (m_part_data.size() > 0) {
         m_part_data.erase(m_part_data.end()-1);
      }
      push_back(body, body_len);
   }

   void
   body_fmt (const char *format, ...)
   {
       char value [255 + 1];
       va_list args;

       va_start (args, format);
       vsnprintf (value, 255, format, args);
       va_end (args);

       body_set (value, 256);
   }

   char * body ()
   {
       if (m_part_data.size())
           return ((char *) m_part_data [m_part_data.size() - 1].data());
       else
           return 0;
   }
   std::vector<uint8_t> body_vector(void)
   {
       if (m_part_data.size())
           return (m_part_data[m_part_data.size() - 1]);
       else
           return std::vector<uint8_t>();
   }
   // zmsg_push
   void push_front(void *part, size_t len) {
      std::vector<uint8_t> tmp((uint8_t*)part, (uint8_t*)part+len);
      m_part_data.insert(m_part_data.begin(), tmp);
   }

   // zmsg_append
   void push_back(const void *part, size_t len) {
      std::vector<uint8_t> tmp((uint8_t*)part, (uint8_t*)part+len);
      m_part_data.push_back(tmp);
   }

   //  --------------------------------------------------------------------------
   //  Formats 17-byte UUID as 33-char string starting with '@'
   //  Lets us print UUIDs as C strings and use them as addresses
   //
   static std::vector<uint8_t>
   encode_uuid (unsigned char *data)
   {
       static uint8_t
           hex_char [] = "0123456789ABCDEF";

       assert (data [0] == 0);
       std::vector<uint8_t> uuidstr(34);
       //char *uuidstr = new char[34];
       uuidstr [0] = '@';
       int byte_nbr;
       for (byte_nbr = 0; byte_nbr < 16; byte_nbr++) {
           uuidstr [byte_nbr * 2 + 1] = hex_char [data [byte_nbr + 1] >> 4];
           uuidstr [byte_nbr * 2 + 2] = hex_char [data [byte_nbr + 1] & 15];
       }
       uuidstr [33] = 0;
       return uuidstr;
   }


   // --------------------------------------------------------------------------
   // Formats 17-byte UUID as 33-char string starting with '@'
   // Lets us print UUIDs as C strings and use them as addresses
   //
   static uint8_t *
   decode_uuid (uint8_t *uuidstr)
   {
       static signed char
           hex_to_bin [128] = {
              -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, /* */
              -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, /* */
              -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, /* */
               0, 1, 2, 3, 4, 5, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1, /* 0..9 */
              -1,10,11,12,13,14,15,-1,-1,-1,-1,-1,-1,-1,-1,-1, /* A..F */
              -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, /* */
              -1,10,11,12,13,14,15,-1,-1,-1,-1,-1,-1,-1,-1,-1, /* a..f */
              -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 }; /* */

       assert (strlen ((char *)uuidstr) == 33);
       assert (uuidstr [0] == '@');
       unsigned char *data = new unsigned char[17];
       int byte_nbr;
       data [0] = 0;
       for (byte_nbr = 0; byte_nbr < 16; byte_nbr++)
           data [byte_nbr + 1]
               = (hex_to_bin [uuidstr [byte_nbr * 2 + 1] & 127] << 4)
               + (hex_to_bin [uuidstr [byte_nbr * 2 + 2] & 127]);

       return (data);
   }

   // zmsg_pop
   std::vector<uint8_t> pop_front() {
      if (m_part_data.size() == 0) {
         return std::vector<uint8_t>();
      }
      std::vector<uint8_t> part = m_part_data.front();
      m_part_data.erase(m_part_data.begin());
      return part;
   }

   void append (const char *part, size_t len)
   {
       assert (part);
       push_back((char*)part, len);
   }

   char *address() {
      if (m_part_data.size()>0) {
         return (char*)m_part_data[0].data();
      } else {
         return 0;
      }
   }

   char *broker_recver() {
      if (m_part_data.size()>4) {
         return (char*)m_part_data[4].data();
      } else {
         return 0;
      }
   }

   int server_cmd_type() {
      if (m_part_data.size()>2) {
         return (int)m_part_data[2][0];
      } else {
         return 0;
      }
   }

   int broker_cmd_type() {
      if (m_part_data.size()>3) {
         return (int)m_part_data[3][0];
      } else {
         return 0;
      }
   }

   void wrap(const char *address, const char *delim) {
      if (delim) {
         push_front((char*)delim, strlen(delim));
      }
      push_front((char*)address, strlen(address));
   }

   std::string unwrap() {
      if (m_part_data.size() == 0) {
         return NULL;
      }
      auto tmp = pop_front();
      std::string addr((char*)tmp.data(), 9);
      if (address() && *address() == 0) {
         pop_front();
      }
      return addr;
   }

   void dump() {
      std::cerr << "--------------------------------------" << std::endl;
      for (unsigned int part_nbr = 0; part_nbr < m_part_data.size(); part_nbr++) {
          auto data = m_part_data [part_nbr];

          // Dump the message as text or binary
          int is_text = 1;
          for (unsigned int char_nbr = 0; char_nbr < data.size(); char_nbr++)
              if (data [char_nbr] < 32 || data [char_nbr] > 127)
                  is_text = 0;

          std::cerr << "[" << std::setw(3) << std::setfill('0') << (int) data.size() << "] ";
          for (unsigned int char_nbr = 0; char_nbr < data.size(); char_nbr++) {
              if (is_text) {
                  std::cerr << (char) data [char_nbr];
              } else {
                  std::cerr << std::hex << std::setw(2) << std::setfill('0') << (short int) data [char_nbr];
              }
          }
          std::cerr << std::endl;
      }
   }


private:
   std::vector<std::vector<uint8_t>> m_part_data;
};

#endif /* ZMSG_H_ */
