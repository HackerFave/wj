
Public Class frmM
    Private m_Baudrate As Byte
    Private m_connect As Byte = 0

    Dim mCan As ComProc = New ComProc


    Private Sub cbbBaudrates_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cbbBaudrates.SelectedIndexChanged
        m_Baudrate = CByte(cbbBaudrates.SelectedIndex)

    End Sub

    Private Sub IncludeTextMessage(ByVal strMsg As String)
        lbxInfo.Items.Add(strMsg)
        lbxInfo.SelectedIndex = lbxInfo.Items.Count - 1
    End Sub

    Private Sub btnInit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnInit.Click
        If m_connect = 1 Then
            m_connect = 0
            mCan.EnableProc = False

            ECAN.ECANDLL.CloseDevice(1, 0)
            btnInit.Text = "打开设备"

            btnReset.Enabled = False
            btnWrite.Enabled = False

            Return
        End If

        Dim init_config As New ECAN.INIT_CONFIG()

        init_config.AccCode = 0
        init_config.AccMask = &HFFFFFF
        init_config.Filter = 0

        Select Case m_Baudrate

            Case 0 '1000

                init_config.Timing0 = 0
                init_config.Timing1 = &H14

            Case 1 '800

                init_config.Timing0 = 0
                init_config.Timing1 = &H16

            Case 2 '666

                init_config.Timing0 = &H80
                init_config.Timing1 = &HB6

            Case 3 '500

                init_config.Timing0 = 0
                init_config.Timing1 = &H1C

            Case 4 '400

                init_config.Timing0 = &H80
                init_config.Timing1 = &HFA

            Case 5 '250

                init_config.Timing0 = &H1
                init_config.Timing1 = &H1C

            Case 6 '200

                init_config.Timing0 = &H81
                init_config.Timing1 = &HFA

            Case 7 '125

                init_config.Timing0 = &H3
                init_config.Timing1 = &H1C

            Case 8 '100

                init_config.Timing0 = &H4
                init_config.Timing1 = &H1C

            Case 9 '80

                init_config.Timing0 = &H83
                init_config.Timing1 = &HFF

            Case 10 '50

                init_config.Timing0 = &H9
                init_config.Timing1 = &H1C


        End Select



        init_config.Mode = 0


        If ECAN.ECANDLL.OpenDevice(1, 0, 0) <> ECAN.ECANStatus.STATUS_OK Then

            MessageBox.Show("Open device fault!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.[Error])

            Return
        End If

        If ECAN.ECANDLL.InitCAN(1, 0, 0, init_config) <> ECAN.ECANStatus.STATUS_OK Then

            MessageBox.Show("Init can fault!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.[Error])

            ECAN.ECANDLL.CloseDevice(1, 0)
            Return
        End If

        m_connect = 1
        mCan.EnableProc = True

        btnInit.Text = "关闭设备"
        btnReset.Enabled = True
        btnWrite.Enabled = True
        IncludeTextMessage("Open Success")


        If m_connect = 0 Then
            MessageBox.Show("Not open device!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.[Error])

            Return
        End If

        If ECAN.ECANDLL.StartCAN(1, 0, 0) = ECAN.ECANStatus.STATUS_OK Then
            IncludeTextMessage("Start Success")

            tmrRead.Enabled = True
        Else
            IncludeTextMessage("Start Fault")
        End If

    End Sub

    Private Sub btnReset_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnReset.Click
        If m_connect = 0 Then
            MessageBox.Show("Not open device!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.[Error])

            Return
        End If
        If ECAN.ECANDLL.ResetCAN(1, 0, 0) = ECAN.ECANStatus.STATUS_OK Then
            IncludeTextMessage("Reset Success")
        Else
            IncludeTextMessage("Reset Fault")
        End If

    End Sub

    Private Sub btnWrite_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnWrite.Click
        If m_connect = 0 Then
            MessageBox.Show("Not open device!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.[Error])
            Return
        End If
        Dim frameinfo As ECAN.CAN_OBJ



        Dim txtbCurrentTextBox As TextBox


        ' We create a TPCANMsg message structure 
        '
        frameinfo = New ECAN.CAN_OBJ()

        frameinfo.data = New Byte(7) {}
        frameinfo.Reserved = New Byte(1) {}

        ' We configurate the Message.  The ID (max 0x1FF),
        ' Length of the Data, Message Type (Standard in 
        ' this example) and die data
        '

        frameinfo.SendType = 0
        frameinfo.ID = Convert.ToUInt32(txtID.Text, 16)
        frameinfo.DataLen = Convert.ToByte(nudLength.Value)


        If chbExtended.Checked Then
            frameinfo.ExternFlag = 1
        Else
            frameinfo.ExternFlag = 0
        End If

        If chbRemote.Checked Then
            frameinfo.RemoteFlag = 1
        Else
            ' We get so much data as the Len of the message
            '

            frameinfo.RemoteFlag = 0

            txtbCurrentTextBox = txtData0
            For i As Integer = 0 To frameinfo.DataLen - 1
                frameinfo.data(i) = Convert.ToByte(txtbCurrentTextBox.Text, 16)
                If i < 7 Then
                    txtbCurrentTextBox = DirectCast(Me.GetNextControl(txtbCurrentTextBox, True), TextBox)
                End If
            Next
        End If


        mCan.gSendMsgBuf(mCan.gSendMsgBufHead).ID = frameinfo.ID
        mCan.gSendMsgBuf(mCan.gSendMsgBufHead).DataLen = frameinfo.DataLen
        mCan.gSendMsgBuf(mCan.gSendMsgBufHead).data = frameinfo.data
        mCan.gSendMsgBuf(mCan.gSendMsgBufHead).ExternFlag = frameinfo.ExternFlag
        mCan.gSendMsgBuf(mCan.gSendMsgBufHead).RemoteFlag = frameinfo.RemoteFlag

        mCan.gSendMsgBufHead = mCan.gSendMsgBufHead + 1
        If (mCan.gSendMsgBufHead) >= ComProc.REC_MSG_BUF_MAX Then
            mCan.gSendMsgBufHead = 0
        End If


    End Sub

    Private Sub btnMsgClear_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnMsgClear.Click
        lbxRec.Items.Clear()

    End Sub

    Private Sub btnInfoClear_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnInfoClear.Click
        lbxInfo.Items.Clear()

    End Sub
    Private Sub ReadMessages()

        Dim stsResult As ECAN.ECANStatus = ECAN.ECANStatus.STATUS_OK
        Dim frameinfo As New ECAN.CAN_OBJ()
        Dim mCount As Integer = 0

        While mCan.gRecMsgBufHead <> mCan.gRecMsgBufTail

            frameinfo = mCan.gRecMsgBuf(mCan.gRecMsgBufTail)
            mCan.gRecMsgBufTail = mCan.gRecMsgBufTail + 1
            If mCan.gRecMsgBufTail >= ComProc.REC_MSG_BUF_MAX Then
                mCan.gRecMsgBufTail = 0
            End If

            '       m_connect = 1 AndAlso stsResult = ECAN.ECANStatus.STATUS_OK

            '
            Dim str As String, tmpstr As String

            str = "Rec: "
            If frameinfo.TimeFlag = 0 Then
                tmpstr = "Time:  "
            Else
                tmpstr = "Time:" & String.Format("{0:X8}h", frameinfo.TimeStamp)
            End If

            str += tmpstr
            tmpstr = "  ID:" & String.Format("{0:X8}h", frameinfo.ID)
            str += tmpstr
            str += " Format:"
            If frameinfo.RemoteFlag = 0 Then
                tmpstr = "Data "
            Else
                tmpstr = "Romte "
            End If
            str += tmpstr
            str += " Type:"
            If frameinfo.ExternFlag = 0 Then
                tmpstr = "Stand "
            Else
                tmpstr = "Exten "
            End If
            str += tmpstr



            If frameinfo.RemoteFlag = 0 Then
                str += " Data:"
                If frameinfo.DataLen > 8 Then
                    frameinfo.DataLen = 8
                End If
                For j As Integer = 0 To frameinfo.DataLen - 1
                    tmpstr = String.Format("{0:X2}h", frameinfo.data(j))
                    str += tmpstr


                Next
            End If

            lbxRec.Items.Add(str)
            '    lbxRec.SelectedIndex = lbxRec.Items.Count - 1

            If lbxRec.Items.Count > 500 Then
                lbxRec.Items.Clear()

            End If
            mCount = mCount + 1
            If mCount >= 50 Then Exit Sub

            Application.DoEvents()

        End While


    End Sub

    Private Sub tmrRead_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles tmrRead.Tick
        ReadMessages()

    End Sub

    Private Sub frmM_FormClosing(ByVal sender As Object, ByVal e As System.Windows.Forms.FormClosingEventArgs) Handles Me.FormClosing


        m_connect = 0
        mCan.EnableProc = False

        ECAN.ECANDLL.CloseDevice(1, 0)
    End Sub

    Private Sub frmM_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        cbbBaudrates.SelectedIndex = 0

    End Sub


   
End Class