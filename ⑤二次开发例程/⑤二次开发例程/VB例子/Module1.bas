Attribute VB_Name = "Module1"
'定义需要用到的数据结构


Public Type CAN_OBJ
    ID As Long
    TimeStamp As Long
    TimeFlag As Byte
    SendType As Byte
    RemoteFlag As Byte
    ExternFlag As Byte
    DataLen As Byte
    data(7) As Byte
    Reserved(2) As Byte
End Type


Public Type init_config
    AccCode As Long
    AccMask As Long
    Reserved As Long
    Filter As Byte
    Timing0 As Byte
    Timing1 As Byte
    Mode As Byte
End Type



Declare Function OpenDevice Lib "ECANVCI.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal Reserved As Long) As Long

Declare Function CloseDevice Lib "ECANVCI.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long) As Long

Declare Function InitCAN Lib "ECANVCI.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long, ByRef InitConfig As init_config) As Long

Declare Function StartCAN Lib "ECANVCI.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long) As Long

Declare Function ResetCAN Lib "ECANVCI.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long) As Long

Declare Function Transmit Lib "ECANVCI.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long, ByRef Send As CAN_OBJ, ByVal length As Long) As Long

Declare Function Receive Lib "ECANVCI.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long, ByRef Receive As CAN_OBJ, ByVal length As Long, ByVal WaitTime As Long) As Long

