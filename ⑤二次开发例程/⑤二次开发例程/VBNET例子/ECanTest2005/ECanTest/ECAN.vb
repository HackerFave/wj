Imports System.Collections.Generic
Imports System.Text
Imports System.Runtime.InteropServices

Namespace ECAN
    <Flags()> _
    Public Enum ECANStatus As UInteger
        ''' <summary>
        '''  error
        ''' </summary>
        STATUS_ERR = &H0
        ''' <summary>
        ''' No error
        ''' </summary>
        STATUS_OK = &H1


    End Enum

    Public Structure CAN_OBJ


        Public ID As UInteger

        Public TimeStamp As UInteger
        Public TimeFlag As Byte
        Public SendType As Byte

        Public RemoteFlag As Byte
        Public ExternFlag As Byte


        Public DataLen As Byte

        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=8)> _
        Public data As Byte()

        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=3)> _
        Public Reserved As Byte()


    End Structure


    Public Structure INIT_CONFIG


        Public AccCode As UInteger
        Public AccMask As UInteger
        Public reserved As UInteger

        Public Filter As Byte

        Public Timing0 As Byte
        Public Timing1 As Byte
        Public Mode As Byte



    End Structure


    Public Class ECANDLL
        Private Sub New()
        End Sub

        <DllImport("ECANVCI.dll", EntryPoint:="OpenDevice")> _
        Public Shared Function OpenDevice(ByVal DeviceType As UInt32, ByVal DeviceInd As UInt32, ByVal Reserved As UInt32) As ECANStatus
        End Function

        <DllImport("ECANVCI.dll", EntryPoint:="CloseDevice")> _
        Public Shared Function CloseDevice(ByVal DeviceType As UInt32, ByVal DeviceInd As UInt32) As ECANStatus
        End Function


        <DllImport("ECANVCI.dll", EntryPoint:="InitCAN")> _
        Public Shared Function InitCAN(ByVal DeviceType As UInt32, ByVal DeviceInd As UInt32, ByVal CANInd As UInt32, ByRef InitConfig As INIT_CONFIG) As ECANStatus
        End Function


        <DllImport("ECANVCI.dll", EntryPoint:="StartCAN")> _
        Public Shared Function StartCAN(ByVal DeviceType As UInt32, ByVal DeviceInd As UInt32, ByVal CANInd As UInt32) As ECANStatus
        End Function


        <DllImport("ECANVCI.dll", EntryPoint:="ResetCAN")> _
        Public Shared Function ResetCAN(ByVal DeviceType As UInt32, ByVal DeviceInd As UInt32, ByVal CANInd As UInt32) As ECANStatus
        End Function


        <DllImport("ECANVCI.dll", EntryPoint:="Transmit")> _
        Public Shared Function Transmit(ByVal DeviceType As UInt32, ByVal DeviceInd As UInt32, ByVal CANInd As UInt32, ByRef Send As CAN_OBJ, ByVal length As UInt16) As ECANStatus
        End Function


        <DllImport("ECANVCI.dll", EntryPoint:="Receive")> _
        Public Shared Function Receive(ByVal DeviceType As UInt32, ByVal DeviceInd As UInt32, ByVal CANInd As UInt32, ByRef mReceive As CAN_OBJ, ByVal length As UInt32, ByVal WaitTime As UInt32) As ECANStatus
        End Function

    End Class



End Namespace
