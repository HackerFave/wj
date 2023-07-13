VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5955
   ClientLeft      =   1950
   ClientTop       =   2550
   ClientWidth     =   8910
   LinkTopic       =   "Form1"
   ScaleHeight     =   5955
   ScaleWidth      =   8910
   Begin VB.Timer Timer1 
      Interval        =   1
      Left            =   7920
      Top             =   1920
   End
   Begin VB.CommandButton cmdReset 
      Caption         =   "复位CAN"
      Height          =   330
      Left            =   4080
      TabIndex        =   7
      Top             =   360
      Width           =   1005
   End
   Begin VB.CommandButton Connect 
      Caption         =   "连接"
      Height          =   330
      Left            =   2640
      TabIndex        =   1
      Top             =   360
      Width           =   1005
   End
   Begin VB.Frame Frame1 
      Caption         =   " 发送数据帧 "
      Height          =   2190
      Left            =   120
      TabIndex        =   0
      Top             =   960
      Width           =   8595
      Begin VB.ComboBox cmbType 
         Height          =   300
         ItemData        =   "Form1.frx":0000
         Left            =   960
         List            =   "Form1.frx":000A
         Style           =   2  'Dropdown List
         TabIndex        =   16
         Top             =   240
         Width           =   1215
      End
      Begin VB.ComboBox cmbFormat 
         Height          =   300
         ItemData        =   "Form1.frx":001E
         Left            =   960
         List            =   "Form1.frx":0028
         Style           =   2  'Dropdown List
         TabIndex        =   15
         Top             =   720
         Width           =   1215
      End
      Begin VB.TextBox txtData 
         Height          =   285
         Left            =   960
         TabIndex        =   14
         Text            =   "01 02 03 04 05 06 07 08 "
         Top             =   1680
         Width           =   3855
      End
      Begin VB.TextBox txtID 
         Height          =   285
         Left            =   960
         TabIndex        =   13
         Text            =   "00000080"
         Top             =   1200
         Width           =   1215
      End
      Begin VB.CommandButton cmdSend 
         Caption         =   "发送"
         Height          =   330
         Left            =   5160
         TabIndex        =   5
         Top             =   1680
         Width           =   870
      End
      Begin VB.Label Label4 
         Caption         =   "帧类型："
         Height          =   195
         Left            =   240
         TabIndex        =   12
         Top             =   360
         Width           =   810
      End
      Begin VB.Label Label7 
         Caption         =   "数据："
         Height          =   240
         Left            =   240
         TabIndex        =   4
         Top             =   1680
         Width           =   555
      End
      Begin VB.Label Label6 
         Caption         =   "帧ID："
         Height          =   195
         Left            =   240
         TabIndex        =   3
         Top             =   1200
         Width           =   585
      End
      Begin VB.Label Label5 
         Caption         =   "帧格式："
         Height          =   195
         Left            =   240
         TabIndex        =   2
         Top             =   720
         Width           =   765
      End
   End
   Begin VB.Frame Frame2 
      Caption         =   "设备参数"
      Height          =   855
      Left            =   120
      TabIndex        =   6
      Top             =   120
      Width           =   6855
      Begin VB.ComboBox cmbBaud 
         Height          =   300
         ItemData        =   "Form1.frx":003C
         Left            =   1080
         List            =   "Form1.frx":0061
         TabIndex        =   10
         Top             =   240
         Width           =   1215
      End
      Begin VB.Label Label1 
         Caption         =   "波特率："
         Height          =   255
         Left            =   240
         TabIndex        =   11
         Top             =   360
         Width           =   855
      End
   End
   Begin VB.Frame Frame6 
      Caption         =   "信息"
      Height          =   2535
      Left            =   120
      TabIndex        =   8
      Top             =   3240
      Width           =   8655
      Begin VB.ListBox List1 
         Height          =   2040
         Left            =   120
         TabIndex        =   9
         Top             =   240
         Width           =   8415
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim m_devtype As Long
Dim m_connect As Byte
Dim m_devind As Long
Dim m_cannum As Long

'1000 K
'800 K
'666 K
'500 K
'400 K
'250 K
'200 K
'125 K
'100 K
'80 K
'50 K

Private Sub cmbBaud_Click()
    Dim CurSel As Byte
    CurSel = cmbBaud.ListIndex

End Sub

Private Sub cmdSend_Click()
    If m_connect = 0 Then
        MsgBox ("请先打开端口")
        Exit Sub
    End If
    
    Dim frameformat, frametype As Byte
    Dim ID As Long
    Dim data(7) As Byte
    Dim frameinfo As CAN_OBJ
    Dim str As String
    
    
    frameformat = cmbFormat.ListIndex
    frametype = cmbType.ListIndex
    str = "&H"
    str = str + txtID.Text
    ID = Val(str)
    str = txtData.Text
    strdata = " "
    i = 0
    For i = 0 To 7
       strdata = Left(str, 2)
       If Len(strdata) = 0 Then
          Exit For
       End If
       str = Right(str, Len(str) - 3)
       data(i) = Val("&H" + strdata)
    Next
    
    frameinfo.DataLen = i
    frameinfo.ExternFlag = frametype
    frameinfo.RemoteFlag = frameformat
    frameinfo.SendType = 0
    frameinfo.ID = ID
    For j = 0 To i - 1
        frameinfo.data(j) = data(j)
    Next
    If Transmit(m_devtype, m_devind, m_cannum, frameinfo, 1) <> 1 Then
        MsgBox ("发送数据失败")
    Else
        List1.AddItem "发送数据成功", List1.ListCount
    End If

End Sub



Private Sub cmdReset_Click()
    If m_connect = 0 Then
        MsgBox ("请先打开端口")
        Exit Sub
    End If
    If ResetCAN(m_devtype, m_devind, m_cannum) <> 1 Then
        MsgBox ("复位CAN错误")
   Else
        List1.AddItem "复位CAN成功", List1.ListCount
    End If

End Sub



Private Sub Connect_Click()
    Dim index As Long
    Dim cannum As Long
    Dim code, mask As Long
    Dim baudSel As Byte
    Dim init_config As init_config
    
    
    If m_connect = 1 Then
        m_connect = 0
        Connect.Caption = "连接"
        CloseDevice m_devtype, m_devind
        
        
        cmbBaud.Enabled = True
        cmbBaud_Click
            
        Exit Sub
    End If
        

     On Error GoTo error
    
        If OpenDevice(m_devtype, index, 0) <> 1 Then
            MsgBox ("打开设备错误")
        Else
            
            baudSel = cmbBaud.ListIndex
            
        
        
             
            init_config.AccCode = 0
            init_config.AccMask = &HFFFFFF
            init_config.Filter = 0

            Select Case baudSel
            
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
            
            
            If InitCAN(m_devtype, index, cannum, init_config) <> 1 Then
                MsgBox ("初始化CAN错误")
                CloseDevice m_devtype, m_devind
                Exit Sub
            End If
            
        
                     
            cmbBaud.Enabled = False
            
            m_connect = 1
            Connect.Caption = "断开"
            
            
        End If
        
        
     If m_connect = 0 Then
        MsgBox ("请先打开端口")
        Exit Sub
    End If
    If StartCAN(m_devtype, m_devind, m_cannum) <> 1 Then
        MsgBox ("启动CAN错误")
    Else
        List1.AddItem "启动CAN成功", List1.ListCount
    End If
    
  
    
    Exit Sub
    
error:
    MsgBox ("设备错误！")
    
End Sub

Private Sub Form_Load()
    m_devtype = 1 'USBCAN1
    m_connect = 0
    m_cannum = 0
    
    cmbType.ListIndex = 0
    cmbFormat.ListIndex = 0
    cmbBaud.ListIndex = 0
    cmbBaud_Click
  ' Call VCI_GetReference(0, 0, 0, 0, 0)
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    If m_connect = 1 Then
        m_connect = 0
        CloseDevice m_devtype, m_devind
    End If
End Sub



Private Sub Timer1_Timer()
    Timer1.Enabled = False
    
    
    If m_connect = 0 Then
        Timer1.Enabled = True
        Exit Sub
    End If

    Dim length As Long
    Dim frameinfo(49) As CAN_OBJ
    Dim str As String
    
    length = Receive(m_devtype, m_devind, m_cannum, frameinfo(0), 50, 10)
    If length <= 0 Then
        Timer1.Enabled = True
        Exit Sub
    End If
    
    For i = 0 To length - 1
        str = "接收到数据帧:  "
        If frameinfo(i).TimeFlag = 0 Then
            tmpstr = "时间标识:无  "
        Else
            tmpstr = "时间标识:0x" + Hex(frameinfo(i).TimeStamp)
        End If
        str = str + tmpstr
        tmpstr = "  帧ID:0x" + Hex(frameinfo(i).ID)
        str = str + tmpstr
        str = str + "  帧格式:"
        If frameinfo(i).RemoteFlag = 0 Then
            tmpstr = "数据帧 "
        Else
            tmpstr = "远程帧 "
        End If
        str = str + tmpstr
        str = str + "  帧类型:"
        If frameinfo(i).ExternFlag = 0 Then
            tmpstr = "标准帧 "
        Else
            tmpstr = "扩展帧 "
        End If
        str = str + tmpstr
        List1.AddItem str, List1.ListCount
        If frameinfo(i).RemoteFlag = 0 Then
            str = "  数据:"
            If frameinfo(i).DataLen > 8 Then
                frameinfo(i).DataLen = 8
            End If
            For j = 0 To frameinfo(i).DataLen - 1
                tmpstr = Hex(frameinfo(i).data(j)) + " "
                str = str + tmpstr
            Next
            List1.AddItem str, List1.ListCount
        End If
        If List1.ListCount > 20000 Then
            List1.Clear
        End If
    Next
    Timer1.Enabled = True
End Sub
