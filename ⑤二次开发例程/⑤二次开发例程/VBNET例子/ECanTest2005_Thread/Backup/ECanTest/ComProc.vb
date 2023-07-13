Imports System.Threading

Public Class ComProc

    Public Const SEND_MSG_BUF_MAX = 10000
    Public gSendMsgBuf(SEND_MSG_BUF_MAX) As ECAN.CAN_OBJ
    Public gSendMsgBufHead As UInt32 = 0
    Public gSendMsgBufTail As UInt32 = 0


    Public Const REC_MSG_BUF_MAX = 10000
    Public gRecMsgBuf(REC_MSG_BUF_MAX) As ECAN.CAN_OBJ
    Public gRecMsgBufHead As UInt32 = 0
    Public gRecMsgBufTail As UInt32 = 0



    Private RecCount_1 As UInt16 = 0
    Private recFirst_1 As Int16 = 1


    Public EnableProc As Boolean = False


    Private _RecTimer As Threading.Timer
    Private RecEvent As Threading.AutoResetEvent
    Private RecTimerDelegate As Threading.TimerCallback


    Private _SendTimer As Threading.Timer
    Private SendEvent As Threading.AutoResetEvent
    Private SendTimerDelegate As Threading.TimerCallback


    Sub New()


        RecEvent = New Threading.AutoResetEvent(False)
        RecTimerDelegate = AddressOf RecTimer_Tick
        _RecTimer = New Threading.Timer(RecTimerDelegate, RecEvent, 0, 20)


        SendEvent = New Threading.AutoResetEvent(False)
        SendTimerDelegate = AddressOf SendTimer_Tick
        _SendTimer = New Threading.Timer(SendTimerDelegate, SendEvent, 0, 20)


    End Sub


    Private Sub RecTimer_Tick(ByVal mObject As Object)

        RecTime()

    End Sub

    Private Sub SendTimer_Tick(ByVal mObject As Object)
        SendTime()
    End Sub


    Public Sub RecTime()
        If EnableProc Then
            ReadMessages()

        End If
    End Sub

    Public Sub SendTime()
        If EnableProc Then
            SendMessages()
        End If

    End Sub

    Private Sub ReadMessages()



        Dim stsResult As ECan.ECANStatus
        Dim mMsg As ECAN.CAN_OBJ = New ECAN.CAN_OBJ
        Dim mLen As UInt32
        Dim overlp As Overlapped = New Overlapped
        Dim sCount As Integer = 0

        '			
        Do
            '
            mLen = 1
            stsResult = ECAN.ECANDLL.Receive(1, 0, 0, mMsg, mLen, 20)

            '
            If stsResult = ECAN.ECANStatus.STATUS_OK And mLen > 0 Then

                Dim recMSG As ECAN.CAN_OBJ = New ECAN.CAN_OBJ
                gRecMsgBuf(gRecMsgBufHead).ID = mMsg.ID
                gRecMsgBuf(gRecMsgBufHead).DataLen = mMsg.DataLen
                gRecMsgBuf(gRecMsgBufHead).data = mMsg.data
                gRecMsgBuf(gRecMsgBufHead).ExternFlag = mMsg.ExternFlag
                gRecMsgBuf(gRecMsgBufHead).RemoteFlag = mMsg.RemoteFlag

                gRecMsgBufHead = gRecMsgBufHead + 1
                If (gRecMsgBufHead) >= REC_MSG_BUF_MAX Then
                    gRecMsgBufHead = 0
                End If



            Else

                Exit Do

            End If

            sCount = sCount + 1
            If sCount >= 500 Then
                Exit Do

            End If

        Loop


    End Sub

  

    Private Sub SendMessages()
        Dim stsResult As ECan.ECANStatus
        Dim mMsg As ECAN.CAN_OBJ
        Dim mLen As UInt32
        Dim sCount As Integer = 0

        Do
            '


            If gSendMsgBufHead = gSendMsgBufTail Then

                Exit Do

            End If

            mMsg = gSendMsgBuf(gSendMsgBufTail)
            gSendMsgBufTail = gSendMsgBufTail + 1
            If gSendMsgBufTail >= SEND_MSG_BUF_MAX Then
                gSendMsgBufTail = 0
            End If

            mLen = 1
            stsResult = ECAN.ECANDLL.Transmit(1, 0, 0, mMsg, mLen)


            If stsResult <> ECAN.ECANStatus.STATUS_OK Then

                '             msgbox("Transmit send fault" )

            End If
            sCount = sCount + 1


            If sCount >= 200 Then
                Exit Do

            End If


        Loop
    End Sub

    
    Public Sub Close()


    End Sub
End Class
