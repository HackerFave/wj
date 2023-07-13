# --*--utf8--*--
import ctypes
import tkinter.ttk
from ctypes import *
from tkinter import *
from tkinter.tix import *
from tkinter import ttk
from tkinter.messagebox import *
import os,sys
import threading

DevType = c_uint

'''
    Device Type
'''
USBCAN1 = DevType(3)
USBCAN2 = DevType(4)
USBCANFD = DevType(6)
'''
    Device Index
'''
DevIndex = c_uint(0)  # 设备索引
'''
    Channel
'''
Channel1 = c_uint(0)  # CAN1
Channel2 = c_uint(1)  # CAN2
'''
    ECAN Status
'''
STATUS_ERR = 0
STATUS_OK = 1

'''
    Device Information
'''


class BoardInfo(Structure):
    _fields_ = [("hw_Version", c_ushort),  # 硬件版本号，用16进制表示
                ("fw_Version", c_ushort),  # 固件版本号，用16进制表示
                ("dr_Version", c_ushort),  # 驱动程序版本号，用16进制表示
                ("in_Version", c_ushort),  # 接口库版本号，用16进制表示
                ("irq_Num", c_ushort),  # 板卡所使用的中断号
                ("can_Num", c_byte),  # 表示有几路CAN通道
                ("str_Serial_Num", c_byte * 20),  # 此板卡的序列号，用ASC码表示
                ("str_hw_Type", c_byte * 40),  # 硬件类型，用ASC码表示
                ("Reserved", c_byte * 4)]  # 系统保留


class CAN_OBJ(Structure):
    _fields_ = [("ID", c_uint),  # 报文帧ID
                ("TimeStamp", c_uint),  # 接收到信息帧时的时间标识，从CAN控制器初始化开始计时，单位微秒
                ("TimeFlag", c_byte),  # 是否使用时间标识，为1时TimeStamp有效，TimeFlag和TimeStamp只在此帧为接收帧时有意义。
                ("SendType", c_byte),
                # 发送帧类型。=0时为正常发送，=1时为单次发送（不自动重发），=2时为自发自收（用于测试CAN卡是否损坏），=3时为单次自发自收（只发送一次，用于自测试），只在此帧为发送帧时有意义
                ("RemoteFlag", c_byte),  # 是否是远程帧。=0时为数据帧，=1时为远程帧
                ("ExternFlag", c_byte),  # 是否是扩展帧。=0时为标准帧（11位帧ID），=1时为扩展帧（29位帧ID）
                ("DataLen", c_byte),  # 数据长度DLC(<=8)，即Data的长度
                ("data", c_ubyte * 8),  # CAN报文的数据。空间受DataLen的约束
                ("Reserved", c_byte * 3)]  # 系统保留。


class INIT_CONFIG(Structure):
    _fields_ = [("acccode", c_uint32),  # 验收码。SJA1000的帧过滤验收码
                ("accmask", c_uint32),  # 屏蔽码。SJA1000的帧过滤屏蔽码。屏蔽码推荐设置为0xFFFF FFFF，即全部接收
                ("reserved", c_uint32),  # 保留
                ("filter", c_byte),  # 滤波使能。0=不使能，1=使能。使能时，请参照SJA1000验收滤波器设置验收码和屏蔽码
                ("timing0", c_byte),  # 波特率定时器0,详见动态库使用说明书7页
                ("timing1", c_byte),  # 波特率定时器1,详见动态库使用说明书7页
                ("mode", c_byte)]  # 模式。=0为正常模式，=1为只听模式，=2为自发自收模式。


import _ctypes

cwdx = os.getcwd()


class ECAN(object):
    def __init__(self):
        self.dll = cdll.LoadLibrary(cwdx + '/ECanVci64.dll')
        if self.dll == None:
            print("DLL Couldn't be loaded")

    def OpenDevice(self, DeviceType, DeviceIndex):
        try:
            return self.dll.OpenDevice(DeviceType, DeviceIndex, 0)
        except:
            print("Exception on OpenDevice!")
            raise

    def CloseDevice(self, DeviceType, DeviceIndex):
        try:
            return self.dll.CloseDevice(DeviceType, DeviceIndex, 0)
        except:
            print("Exception on CloseDevice!")
            raise

    def InitCan(self, DeviceType, DeviceIndex, CanInd, Initconfig):
        try:
            return self.dll.InitCAN(DeviceType, DeviceIndex, CanInd, byref(Initconfig))
        except:
            print("Exception on InitCan!")
            raise

    def StartCan(self, DeviceType, DeviceIndex, CanInd):
        try:
            return self.dll.StartCAN(DeviceType, DeviceIndex, CanInd)
        except:
            print("Exception on StartCan!")
            raise

    def ReadBoardInfo(self, DeviceType, DeviceIndex):
        try:
            mboardinfo = BoardInfo()
            ret = self.dll.ReadBoardInfo(DeviceType, DeviceIndex, byref(mboardinfo))
            return mboardinfo, ret
        except:
            print("Exception on ReadBoardInfo!")
            raise

    def Receivce(self, DeviceType, DeviceIndex, CanInd, length):
        try:
            recmess = (CAN_OBJ * length)()
            ret = self.dll.Receive(DeviceType, DeviceIndex, CanInd, byref(recmess), length, 0)
            return length, recmess, ret
        except:
            print("Exception on Receive!")
            raise

    def Tramsmit(self, DeviceType, DeviceIndex, CanInd, mcanobj):
        try:
            # mCAN_OBJ=CAN_OBJ*2
            # self.dll.Transmit.argtypes = [ctypes.c_uint32, ctypes.c_uint32, ctypes.c_uint32, POINTER(CAN_OBJ),
            # ctypes.c_uint16]
            return self.dll.Transmit(DeviceType, DeviceIndex, CanInd, byref(mcanobj), c_uint16(1))
        except:
            print("Exception on Tramsmit!")
            raise

# 加载动态库
ecan = ECAN()

if hasattr(sys,'frozen'):
    os.environ['PATH']=sys._MEIPASS+":"+os.environ['PATH']
root = Tk()  # 初始化Tk()
root.title("EcanTest")
# root.geometry("800x1000")
root.resizable(width=TRUE, height=True)
root.tk.eval('package require Tix')
musbcanopen = False
rec_CAN1 = 1
rec_CAN2 = 1
'''
读取数据
'''


def ReadCAN():
    global musbcanopen, rec_CAN1, rec_CAN2
    if (musbcanopen == True):
        scount = 0
        while (scount < 50):
            scount=scount+1
            len, rec, ret = ecan.Receivce(USBCAN2, DevIndex, Channel1, 1)
            if (len > 0 and ret == 1):
                mstr = "Rec: " + str(rec_CAN1)
                rec_CAN1 = rec_CAN1 + 1
                if rec[0].TimeFlag == 0:
                    mstr = mstr + " Time: "
                else:
                    mstr = mstr + " Time:" + hex(rec[0].TimeStamp).zfill(8)
                if rec[0].ExternFlag == 0:
                    mstr = mstr + " ID:" + hex(rec[0].ID).zfill(3) + " Format:Stand "
                else:
                    mstr = mstr + " ID:" + hex(rec[0].ID).zfill(8) + " Format:Exten "
                if rec[0].RemoteFlag == 0:
                    mstr = mstr + " Type:Data " + " Data: "
                    for i in range(0, rec[0].DataLen):
                        mstr = mstr + hex(rec[0].data[i]).zfill(2) + " "
                else:
                    mstr = mstr + " Type:Romte " + " Data: Remote Request"

                if listreadcan1.size() > 1000:
                    listreadcan1.delete(0, END)
                listreadcan1.insert("end", mstr)
                listreadcan1.see(listreadcan1.size())
            len2, rec2, ret2 = ecan.Receivce(USBCAN2, DevIndex, Channel2, 1)
            if (len2 > 0 and ret2 == 1):
                mstr = "Rec: " + str(rec_CAN2)
                rec_CAN2 = rec_CAN2 + 1
                if rec2[0].TimeFlag == 0:
                    mstr = mstr + " Time: "
                else:
                    mstr = mstr + " Time:" + hex(rec2[0].TimeStamp).zfill(8)
                if rec2[0].ExternFlag == 0:
                    mstr = mstr + " ID:" + hex(rec2[0].ID).zfill(3) + " Format:Stand "
                else:
                    mstr = mstr + " ID:" + hex(rec2[0].ID).zfill(8) + " Format:Exten "
                if rec2[0].RemoteFlag == 0:
                    mstr = mstr + " Type:Data " + " Data: "
                    for i in range(0, rec2[0].DataLen):
                        mstr = mstr + hex(rec2[0].data[i]).zfill(2) + " "
                else:
                    mstr = mstr + " Type:Romte " + " Data: Remote Request"

                if listreadcan2.size() > 1000:
                    listreadcan2.delete(0, END)
                listreadcan2.insert("end", mstr)
                listreadcan2.see(listreadcan2.size())



        t = threading.Timer(0.03, ReadCAN)
        t.start()


t = threading.Timer(0.03, ReadCAN)


# python调用动态库默认参数为整型


def caninit():
    global musbcanopen, t, rec_CAN1, rec_CAN2
    if (musbcanopen == False):
        initconfig = INIT_CONFIG()
        initconfig.acccode = 0  # 设置验收码
        initconfig.accmask = 0xFFFFFFFF  # 设置屏蔽码
        initconfig.filter = 0  # 设置滤波使能
        mbaudcan1 = baudvaluecan1.get()
        mbaudcan2 = baudvaluecan2.get()
        # 打开设备
        if (ecan.OpenDevice(USBCAN2, DevIndex) != STATUS_OK):
            tkinter.messagebox.showinfo("ERROR", "OpenDevice Failed!")
            return
        initconfig.timing0, initconfig.timing1 = getTiming(mbaudcan1)
        initconfig.mode = 0
        # 初始化CAN1
        if (ecan.InitCan(USBCAN2, DevIndex, Channel1, initconfig) != STATUS_OK):
            tkinter.messagebox.showinfo("ERROR", "InitCan CAN1 Failed!")
            ecan.CloseDevice(USBCAN2, DevIndex)
            return
        # 初始化CAN2
        initconfig.timing0, initconfig.timing1 = getTiming(mbaudcan2)
        if (ecan.InitCan(USBCAN2, DevIndex, Channel2, initconfig) != STATUS_OK):
            tkinter.messagebox.showinfo("ERROR", "InitCan CAN2 Failed!")
            ecan.CloseDevice(USBCAN2, DevIndex)
            return
        if (ecan.StartCan(USBCAN2, DevIndex, Channel1) != STATUS_OK):
            tkinter.messagebox.showinfo("ERROR", "StartCan CAN1 Failed!")
            ecan.CloseDevice(USBCAN2, DevIndex)
            return
        if (ecan.StartCan(USBCAN2, DevIndex, Channel2) != STATUS_OK):
            tkinter.messagebox.showinfo("ERROR", "StartCan CAN2 Failed!")
            ecan.CloseDevice(USBCAN2, DevIndex)
            return
        musbcanopen = True
        rec_CAN1 = 1
        rec_CAN2 = 1
        btopen.configure(text="关闭设备")
        btreadinfo.configure(state='normal')
        bt_send_CAN1.configure(state='normal')
        bt_send_CAN2.configure(state='normal')
        t = threading.Timer(0.03, ReadCAN)
        t.start()
    else:
        musbcanopen = False
        ecan.CloseDevice(USBCAN2, DevIndex)
        btopen.configure(text="打开设备")
        lbsn.configure(text="SN:")
        btreadinfo.configure(state='disabled')
        bt_send_CAN1.configure(state='disabled')
        bt_send_CAN2.configure(state='disabled')


'''
读取SN号码
'''


def readmess():
    global musbcanopen
    if (musbcanopen == False):
        tkinter.messagebox.showinfo("ERROR", "请先打开设备")
    else:
        mboardinfo, ret = ecan.ReadBoardInfo(USBCAN2, DevIndex)  # 读取设备信息需要在打开设备后执行
        if ret == STATUS_OK:
            mstr = ""
            for i in range(0, 10):
                mstr = mstr + chr(mboardinfo.str_Serial_Num[i])  # 结构体中str_Serial_Num内部存放存放SN号的ASC码
            lbsn.configure(text="SN:" + mstr)

        else:
            lbsn.configure(text="Read info Fault")


def getTiming(mbaud):
    if mbaud == "1M":
        return 0, 0x14
    if mbaud == "800k":
        return 0, 0x16
    if mbaud == "666k":
        return 0x80, 0xb6
    if mbaud == "500k":
        return 0, 0x1c
    if mbaud == "400k":
        return 0x80, 0xfa
    if mbaud == "250k":
        return 0x01, 0x1c
    if mbaud == "200k":
        return 0x81, 0xfa
    if mbaud == "125k":
        return 0x03, 0x1c
    if mbaud == "100k":
        return 0x04, 0x1c
    if mbaud == "80k":
        return 0x83, 0xff
    if mbaud == "50k":
        return 0x09, 0x1c


def clearcan1():
    listreadcan1.delete(0, END)


def clearcan2():
    listreadcan2.delete(0, END)


def sendcan1():
    global musbcanopen
    if (musbcanopen == False):
        tkinter.messagebox.showinfo("ERROR", "请先打开设备")
    else:
        canobj = CAN_OBJ()
        canobj.ID = int(e_ID_CAN1.get(), 16)
        canobj.DataLen = int(ct_Length_CAN1['value'])
        canobj.data[0] = int(e_Data0_CAN1.get(), 16)
        canobj.data[1] = int(e_Data1_CAN1.get(), 16)
        canobj.data[2] = int(e_Data2_CAN1.get(), 16)
        canobj.data[3] = int(e_Data3_CAN1.get(), 16)
        canobj.data[4] = int(e_Data4_CAN1.get(), 16)
        canobj.data[5] = int(e_Data5_CAN1.get(), 16)
        canobj.data[6] = int(e_Data6_CAN1.get(), 16)
        canobj.data[7] = int(e_Data7_CAN1.get(), 16)
        canobj.RemoteFlag = rtr_CAN1.get()
        canobj.ExternFlag = ext_CAN1.get()
        ecan.Tramsmit(USBCAN2, DevIndex, Channel1, canobj)

def sendcan2():
    global musbcanopen
    if (musbcanopen == False):
        tkinter.messagebox.showinfo("ERROR", "请先打开设备")
    else:
        canobj = CAN_OBJ()
        canobj.ID = int(e_ID_CAN2.get(), 16)
        canobj.DataLen = int(ct_Length_CAN2['value'])
        canobj.data[0] = int(e_Data0_CAN2.get(), 16)
        canobj.data[1] = int(e_Data1_CAN2.get(), 16)
        canobj.data[2] = int(e_Data2_CAN2.get(), 16)
        canobj.data[3] = int(e_Data3_CAN2.get(), 16)
        canobj.data[4] = int(e_Data4_CAN2.get(), 16)
        canobj.data[5] = int(e_Data5_CAN2.get(), 16)
        canobj.data[6] = int(e_Data6_CAN2.get(), 16)
        canobj.data[7] = int(e_Data7_CAN2.get(), 16)
        canobj.RemoteFlag = rtr_CAN2.get()
        canobj.ExternFlag = ext_CAN2.get()
        ecan.Tramsmit(USBCAN2, DevIndex, Channel2, canobj)


lb1 = Label(root, text="CAN1波特率:", bd=3, font=("Arial", 12))
lb1.grid(row=1, column=0, padx=1, pady=1, sticky='w')
lb2 = Label(root, text="CAN2波特率:", bd=3, font=("Arial", 12))
lb2.grid(row=2, column=0, padx=1, pady=1, sticky='w')
lbsn = Label(root, text="SN:", bd=3, font=("Arial", 12), width=30)
lbsn.grid(row=2, column=3, padx=5, pady=5, sticky='w')
tabcontrol = ttk.Notebook(root)
tab1 = ttk.Frame(tabcontrol)
tab2 = ttk.Frame(tabcontrol)
tabcontrol.grid(row=3, columnspan=5, sticky='nw')
tabcontrol.add(tab1, text="CAN1")
tabcontrol.add(tab2, text="CAN2")
baudvaluecan1 = StringVar()
baudvaluecan1.set("250k")
baudvaluecan2 = StringVar()
baudvaluecan2.set("250k")
baudvalues = ["1M", "800k", "666k", "500k", "400k", "250k", "200k", "125k", "100k", "80k", "50k"]
can1com = tkinter.ttk.Combobox(master=root, state="readonly", font=("Arial", 12), textvariable=baudvaluecan1,
                               values=baudvalues)
can1com.grid(row=1, column=1, padx=1, pady=1, sticky='nw')
can2com = tkinter.ttk.Combobox(master=root, state="readonly", font=("Arial", 12), textvariable=baudvaluecan2,
                               values=baudvalues)
can2com.grid(row=2, column=1, padx=1, pady=1, sticky='w')
btopen = Button(root, text="打开设备", command=caninit)
btopen.grid(row=1, column=2, padx=1, pady=1, sticky='w')
btreadinfo = Button(root, text="读取设备信息", command=readmess, state='disabled')
btreadinfo.grid(row=2, column=2, padx=1, pady=1, sticky='w')

lb_ID_CAN1 = Label(tab1, text="ID(Hex)", bd=3, font=("Arial", 12))
lb_ID_CAN1.grid(row=0, column=0, sticky='w')
e_ID_CAN1 = Entry(tab1, bd=3, font=("Arial", 12))
e_ID_CAN1.grid(row=1, column=0, sticky='w')
e_ID_CAN1.insert(0, "00000001")
ext_CAN1 = IntVar()
cb_Ext_CAN1 = Checkbutton(tab1, text="Extended", variable=ext_CAN1, bd=3, font=("Arial", 12))
cb_Ext_CAN1.grid(row=0, column=1, sticky='w')
rtr_CAN1 = IntVar()
cb_Rtr_CAN1 = Checkbutton(tab1, text="RTR", variable=rtr_CAN1, bd=3, font=("Arial", 12))
cb_Rtr_CAN1.grid(row=1, column=1, sticky='w')
ct_Length_CAN1 = Control(tab1, label='Length(0-8):', integer=True, max=8, min=0, value=8, step=1)
ct_Length_CAN1.grid(row=0, column=7, columnspan=4, sticky='w')
s1 = Scrollbar(tab1, orient=VERTICAL)
s1.grid(row=2, column=11,sticky='ns')
listreadcan1 = Listbox(tab1, font=("Arial", 12), height=20, width=90, yscrollcommand=s1.set)
listreadcan1.grid(row=2, column=0, columnspan=11, sticky='nw')
s1.config(command=listreadcan1.yview)

lb_Data_CAN1 = Label(tab1, text="Data(Hex)", bd=3, font=("Arial", 12))
lb_Data_CAN1.grid(row=0, column=3, columnspan=4, sticky='w')
Data0_CAN1 = StringVar()
e_Data0_CAN1 = Entry(tab1, textvariable=Data0_CAN1, width=3, bd=3, font=("Arial", 12))
e_Data0_CAN1.grid(row=1, column=3, padx=2, pady=1, sticky='w')
Data0_CAN1.set('00')
Data1_CAN1 = StringVar()
e_Data1_CAN1 = Entry(tab1, textvariable=Data1_CAN1, width=3, bd=3, font=("Arial", 12))
e_Data1_CAN1.grid(row=1, column=4, padx=2, pady=1, sticky='w')
Data1_CAN1.set('01')
Data2_CAN1 = StringVar()
e_Data2_CAN1 = Entry(tab1, textvariable=Data2_CAN1, width=3, bd=3, font=("Arial", 12))
e_Data2_CAN1.grid(row=1, column=5, padx=2, pady=1, sticky='w')
Data2_CAN1.set('02')
Data3_CAN1 = StringVar()
e_Data3_CAN1 = Entry(tab1, textvariable=Data3_CAN1, width=3, bd=3, font=("Arial", 12))
e_Data3_CAN1.grid(row=1, column=6, padx=2, pady=1, sticky='w')
Data3_CAN1.set('03')
Data4_CAN1 = StringVar()
e_Data4_CAN1 = Entry(tab1, textvariable=Data4_CAN1, width=3, bd=3, font=("Arial", 12))
e_Data4_CAN1.grid(row=1, column=7, padx=2, pady=1, sticky='w')
Data4_CAN1.set('04')
Data5_CAN1 = StringVar()
e_Data5_CAN1 = Entry(tab1, textvariable=Data5_CAN1, width=3, bd=3, font=("Arial", 12))
e_Data5_CAN1.grid(row=1, column=8, padx=2, pady=1, sticky='w')
Data5_CAN1.set('05')
Data6_CAN1 = StringVar()
e_Data6_CAN1 = Entry(tab1, textvariable=Data6_CAN1, width=3, bd=3, font=("Arial", 12))
e_Data6_CAN1.grid(row=1, column=9, padx=2, pady=1, sticky='w')
Data6_CAN1.set('06')
Data7_CAN1 = StringVar()
e_Data7_CAN1 = Entry(tab1, textvariable=Data7_CAN1, width=3, bd=3, font=("Arial", 12))
e_Data7_CAN1.grid(row=1, column=10, padx=2, pady=1, sticky='w')
Data7_CAN1.set('07')
bt_send_CAN1 = Button(tab1, text='发送数据', state='disabled', font=("Arial", 12), bd=3, command=sendcan1)
bt_send_CAN1.grid(row=1, column=12, padx=2, pady=1)
bt_clear_CAN1 = Button(tab1, text='清空', font=("Arial", 12), bd=3, command=clearcan1)
bt_clear_CAN1.grid(row=2, column=12, padx=2, pady=1)

lb_ID_CAN2 = Label(tab2, text="ID(Hex)", bd=3, font=("Arial", 12))
lb_ID_CAN2.grid(row=0, column=0, sticky='w')
e_ID_CAN2 = Entry(tab2, bd=3, font=("Arial", 12))
e_ID_CAN2.grid(row=1, column=0, sticky='w')
e_ID_CAN2.insert(0, "00000001")
ext_CAN2 = IntVar()
cb_Ext_CAN2 = Checkbutton(tab2, text="Extended", variable=ext_CAN2, bd=3, font=("Arial", 12))
cb_Ext_CAN2.grid(row=0, column=1, sticky='w')
rtr_CAN2 = IntVar()
cb_Rtr_CAN2 = Checkbutton(tab2, text="RTR", variable=rtr_CAN2, bd=3, font=("Arial", 12))
cb_Rtr_CAN2.grid(row=1, column=1, sticky='w')
ct_Length_CAN2 = Control(tab2, label='Length(0-8):', integer=True, max=8, min=0, value=8, step=1)
ct_Length_CAN2.grid(row=0, column=7, columnspan=4, sticky='w')
s2 = Scrollbar(tab2, orient=VERTICAL)
s2.grid(row=2, column=11,sticky='ns')
listreadcan2 = Listbox(tab2, font=("Arial", 12), height=20, width=90, yscrollcommand=s2.set)
listreadcan2.grid(row=2, column=0, columnspan=11, sticky='nw')
s2.config(command=listreadcan2.yview)
lb_Data_CAN2 = Label(tab2, text="Data(Hex)", bd=3, font=("Arial", 12))
lb_Data_CAN2.grid(row=0, column=3, columnspan=4, sticky='w')
Data0_CAN2 = StringVar()
e_Data0_CAN2 = Entry(tab2, textvariable=Data0_CAN2, width=3, bd=3, font=("Arial", 12))
e_Data0_CAN2.grid(row=1, column=3, padx=2, pady=1, sticky='w')
Data0_CAN2.set('00')
Data1_CAN2 = StringVar()
e_Data1_CAN2 = Entry(tab2, textvariable=Data1_CAN2, width=3, bd=3, font=("Arial", 12))
e_Data1_CAN2.grid(row=1, column=4, padx=2, pady=1, sticky='w')
Data1_CAN2.set('01')
Data2_CAN2 = StringVar()
e_Data2_CAN2 = Entry(tab2, textvariable=Data2_CAN2, width=3, bd=3, font=("Arial", 12))
e_Data2_CAN2.grid(row=1, column=5, padx=2, pady=1, sticky='w')
Data2_CAN2.set('02')
Data3_CAN2 = StringVar()
e_Data3_CAN2 = Entry(tab2, textvariable=Data3_CAN2, width=3, bd=3, font=("Arial", 12))
e_Data3_CAN2.grid(row=1, column=6, padx=2, pady=1, sticky='w')
Data3_CAN2.set('03')
Data4_CAN2 = StringVar()
e_Data4_CAN2 = Entry(tab2, textvariable=Data4_CAN2, width=3, bd=3, font=("Arial", 12))
e_Data4_CAN2.grid(row=1, column=7, padx=2, pady=1, sticky='w')
Data4_CAN2.set('04')
Data5_CAN2 = StringVar()
e_Data5_CAN2 = Entry(tab2, textvariable=Data5_CAN2, width=3, bd=3, font=("Arial", 12))
e_Data5_CAN2.grid(row=1, column=8, padx=2, pady=1, sticky='w')
Data5_CAN2.set('05')
Data6_CAN2 = StringVar()
e_Data6_CAN2 = Entry(tab2, textvariable=Data6_CAN2, width=3, bd=3, font=("Arial", 12))
e_Data6_CAN2.grid(row=1, column=9, padx=2, pady=1, sticky='w')
Data6_CAN2.set('06')
Data7_CAN2 = StringVar()
e_Data7_CAN2 = Entry(tab2, textvariable=Data7_CAN2, width=3, bd=3, font=("Arial", 12))
e_Data7_CAN2.grid(row=1, column=10, padx=2, pady=1, sticky='w')
Data7_CAN2.set('07')
bt_send_CAN2 = Button(tab2, text='发送数据', state='disabled', font=("Arial", 12), bd=3, command=sendcan2)
bt_send_CAN2.grid(row=1, column=12, padx=2, pady=1)
bt_clear_CAN2 = Button(tab2, text='清空', font=("Arial", 12), bd=3, command=clearcan2)
bt_clear_CAN2.grid(row=2, column=12, padx=2, pady=1)

root.mainloop()
