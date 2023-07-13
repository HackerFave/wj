<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmM
    Inherits System.Windows.Forms.Form

    'Form 重写 Dispose，以清理组件列表。
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows 窗体设计器所必需的
    Private components As System.ComponentModel.IContainer

    '注意: 以下过程是 Windows 窗体设计器所必需的
    '可以使用 Windows 窗体设计器修改它。
    '不要使用代码编辑器修改它。
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Me.chbRemote = New System.Windows.Forms.CheckBox
        Me.groupBox1 = New System.Windows.Forms.GroupBox
        Me.label1 = New System.Windows.Forms.Label
        Me.cbbBaudrates = New System.Windows.Forms.ComboBox
        Me.btnInit = New System.Windows.Forms.Button
        Me.btnReset = New System.Windows.Forms.Button
        Me.chbExtended = New System.Windows.Forms.CheckBox
        Me.lbxInfo = New System.Windows.Forms.ListBox
        Me.btnInfoClear = New System.Windows.Forms.Button
        Me.btnWrite = New System.Windows.Forms.Button
        Me.groupBox5 = New System.Windows.Forms.GroupBox
        Me.lbxRec = New System.Windows.Forms.ListBox
        Me.btnMsgClear = New System.Windows.Forms.Button
        Me.label11 = New System.Windows.Forms.Label
        Me.tmrRead = New System.Windows.Forms.Timer(Me.components)
        Me.label12 = New System.Windows.Forms.Label
        Me.label13 = New System.Windows.Forms.Label
        Me.txtID = New System.Windows.Forms.TextBox
        Me.txtData7 = New System.Windows.Forms.TextBox
        Me.groupBox4 = New System.Windows.Forms.GroupBox
        Me.groupBox6 = New System.Windows.Forms.GroupBox
        Me.txtData6 = New System.Windows.Forms.TextBox
        Me.txtData5 = New System.Windows.Forms.TextBox
        Me.txtData4 = New System.Windows.Forms.TextBox
        Me.txtData3 = New System.Windows.Forms.TextBox
        Me.txtData2 = New System.Windows.Forms.TextBox
        Me.txtData1 = New System.Windows.Forms.TextBox
        Me.txtData0 = New System.Windows.Forms.TextBox
        Me.nudLength = New System.Windows.Forms.NumericUpDown
        Me.tmrDisplay = New System.Windows.Forms.Timer(Me.components)
        Me.groupBox1.SuspendLayout()
        Me.groupBox5.SuspendLayout()
        Me.groupBox4.SuspendLayout()
        Me.groupBox6.SuspendLayout()
        CType(Me.nudLength, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'chbRemote
        '
        Me.chbRemote.Cursor = System.Windows.Forms.Cursors.Default
        Me.chbRemote.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.chbRemote.Location = New System.Drawing.Point(270, 30)
        Me.chbRemote.Name = "chbRemote"
        Me.chbRemote.Size = New System.Drawing.Size(44, 22)
        Me.chbRemote.TabIndex = 33
        Me.chbRemote.Text = "RTR"
        '
        'groupBox1
        '
        Me.groupBox1.Controls.Add(Me.label1)
        Me.groupBox1.Controls.Add(Me.cbbBaudrates)
        Me.groupBox1.Controls.Add(Me.btnInit)
        Me.groupBox1.Controls.Add(Me.btnReset)
        Me.groupBox1.Location = New System.Drawing.Point(12, 12)
        Me.groupBox1.Name = "groupBox1"
        Me.groupBox1.Size = New System.Drawing.Size(545, 79)
        Me.groupBox1.TabIndex = 55
        Me.groupBox1.TabStop = False
        Me.groupBox1.Text = "groupBox1"
        '
        'label1
        '
        Me.label1.AutoSize = True
        Me.label1.Location = New System.Drawing.Point(18, 32)
        Me.label1.Name = "label1"
        Me.label1.Size = New System.Drawing.Size(41, 12)
        Me.label1.TabIndex = 40
        Me.label1.Text = "波特率"
        '
        'cbbBaudrates
        '
        Me.cbbBaudrates.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cbbBaudrates.Items.AddRange(New Object() {"1 MBit/sec", "800 kBit/sec", "666 kBit/sec", "500 kBit/sec", "400 kBit/sec", "250 kBit/sec", "200 kBit/sec", "125 kBit/sec", "100 kBit/sec", "80 kBit/sec", "50 kBit/sec"})
        Me.cbbBaudrates.Location = New System.Drawing.Point(65, 29)
        Me.cbbBaudrates.Name = "cbbBaudrates"
        Me.cbbBaudrates.Size = New System.Drawing.Size(97, 20)
        Me.cbbBaudrates.TabIndex = 39
        '
        'btnInit
        '
        Me.btnInit.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.btnInit.Cursor = System.Windows.Forms.Cursors.Default
        Me.btnInit.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.btnInit.Location = New System.Drawing.Point(168, 28)
        Me.btnInit.Name = "btnInit"
        Me.btnInit.Size = New System.Drawing.Size(65, 21)
        Me.btnInit.TabIndex = 37
        Me.btnInit.Text = "打开设备"
        '
        'btnReset
        '
        Me.btnReset.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.btnReset.Cursor = System.Windows.Forms.Cursors.Default
        Me.btnReset.Enabled = False
        Me.btnReset.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.btnReset.Location = New System.Drawing.Point(258, 29)
        Me.btnReset.Name = "btnReset"
        Me.btnReset.Size = New System.Drawing.Size(65, 21)
        Me.btnReset.TabIndex = 38
        Me.btnReset.Text = "复位"
        '
        'chbExtended
        '
        Me.chbExtended.Cursor = System.Windows.Forms.Cursors.Default
        Me.chbExtended.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.chbExtended.Location = New System.Drawing.Point(94, 30)
        Me.chbExtended.Name = "chbExtended"
        Me.chbExtended.Size = New System.Drawing.Size(80, 22)
        Me.chbExtended.TabIndex = 34
        Me.chbExtended.Text = "Extended"
        '
        'lbxInfo
        '
        Me.lbxInfo.FormattingEnabled = True
        Me.lbxInfo.ItemHeight = 12
        Me.lbxInfo.Location = New System.Drawing.Point(10, 18)
        Me.lbxInfo.Name = "lbxInfo"
        Me.lbxInfo.ScrollAlwaysVisible = True
        Me.lbxInfo.Size = New System.Drawing.Size(558, 100)
        Me.lbxInfo.TabIndex = 56
        '
        'btnInfoClear
        '
        Me.btnInfoClear.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.btnInfoClear.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.btnInfoClear.Location = New System.Drawing.Point(593, 20)
        Me.btnInfoClear.Name = "btnInfoClear"
        Me.btnInfoClear.Size = New System.Drawing.Size(65, 21)
        Me.btnInfoClear.TabIndex = 52
        Me.btnInfoClear.Text = "Clear"
        Me.btnInfoClear.UseVisualStyleBackColor = True
        '
        'btnWrite
        '
        Me.btnWrite.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.btnWrite.Cursor = System.Windows.Forms.Cursors.Default
        Me.btnWrite.Enabled = False
        Me.btnWrite.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.btnWrite.Location = New System.Drawing.Point(610, 29)
        Me.btnWrite.Name = "btnWrite"
        Me.btnWrite.Size = New System.Drawing.Size(65, 21)
        Me.btnWrite.TabIndex = 36
        Me.btnWrite.Text = "Send"
        '
        'groupBox5
        '
        Me.groupBox5.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                    Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.groupBox5.Controls.Add(Me.lbxRec)
        Me.groupBox5.Controls.Add(Me.btnMsgClear)
        Me.groupBox5.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.groupBox5.Location = New System.Drawing.Point(12, 182)
        Me.groupBox5.Name = "groupBox5"
        Me.groupBox5.Size = New System.Drawing.Size(681, 129)
        Me.groupBox5.TabIndex = 58
        Me.groupBox5.TabStop = False
        Me.groupBox5.Text = " Messages Reading "
        '
        'lbxRec
        '
        Me.lbxRec.FormattingEnabled = True
        Me.lbxRec.ItemHeight = 12
        Me.lbxRec.Location = New System.Drawing.Point(6, 20)
        Me.lbxRec.Name = "lbxRec"
        Me.lbxRec.ScrollAlwaysVisible = True
        Me.lbxRec.Size = New System.Drawing.Size(558, 100)
        Me.lbxRec.TabIndex = 57
        '
        'btnMsgClear
        '
        Me.btnMsgClear.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.btnMsgClear.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.btnMsgClear.Location = New System.Drawing.Point(580, 30)
        Me.btnMsgClear.Name = "btnMsgClear"
        Me.btnMsgClear.Size = New System.Drawing.Size(65, 21)
        Me.btnMsgClear.TabIndex = 50
        Me.btnMsgClear.Text = "Clear"
        Me.btnMsgClear.UseVisualStyleBackColor = True
        '
        'label11
        '
        Me.label11.AutoSize = True
        Me.label11.Location = New System.Drawing.Point(267, 16)
        Me.label11.Name = "label11"
        Me.label11.Size = New System.Drawing.Size(77, 12)
        Me.label11.TabIndex = 32
        Me.label11.Text = "Data (0..7):"
        '
        'tmrRead
        '
        '
        'label12
        '
        Me.label12.AutoSize = True
        Me.label12.Location = New System.Drawing.Point(174, 16)
        Me.label12.Name = "label12"
        Me.label12.Size = New System.Drawing.Size(47, 12)
        Me.label12.TabIndex = 31
        Me.label12.Text = "Length:"
        '
        'label13
        '
        Me.label13.AutoSize = True
        Me.label13.Location = New System.Drawing.Point(7, 16)
        Me.label13.Name = "label13"
        Me.label13.Size = New System.Drawing.Size(59, 12)
        Me.label13.TabIndex = 30
        Me.label13.Text = "ID (Hex):"
        '
        'txtID
        '
        Me.txtID.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper
        Me.txtID.Location = New System.Drawing.Point(6, 31)
        Me.txtID.MaxLength = 3
        Me.txtID.Name = "txtID"
        Me.txtID.Size = New System.Drawing.Size(80, 21)
        Me.txtID.TabIndex = 20
        Me.txtID.Text = "0"
        '
        'txtData7
        '
        Me.txtData7.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper
        Me.txtData7.Location = New System.Drawing.Point(544, 31)
        Me.txtData7.MaxLength = 2
        Me.txtData7.Name = "txtData7"
        Me.txtData7.Size = New System.Drawing.Size(24, 21)
        Me.txtData7.TabIndex = 29
        Me.txtData7.Text = "00"
        Me.txtData7.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'groupBox4
        '
        Me.groupBox4.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                    Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.groupBox4.Controls.Add(Me.lbxInfo)
        Me.groupBox4.Controls.Add(Me.btnInfoClear)
        Me.groupBox4.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.groupBox4.Location = New System.Drawing.Point(12, 317)
        Me.groupBox4.Name = "groupBox4"
        Me.groupBox4.Size = New System.Drawing.Size(681, 125)
        Me.groupBox4.TabIndex = 57
        Me.groupBox4.TabStop = False
        Me.groupBox4.Text = "Information"
        '
        'groupBox6
        '
        Me.groupBox6.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
                    Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.groupBox6.Controls.Add(Me.chbRemote)
        Me.groupBox6.Controls.Add(Me.chbExtended)
        Me.groupBox6.Controls.Add(Me.label11)
        Me.groupBox6.Controls.Add(Me.btnWrite)
        Me.groupBox6.Controls.Add(Me.label12)
        Me.groupBox6.Controls.Add(Me.label13)
        Me.groupBox6.Controls.Add(Me.txtID)
        Me.groupBox6.Controls.Add(Me.txtData7)
        Me.groupBox6.Controls.Add(Me.txtData6)
        Me.groupBox6.Controls.Add(Me.txtData5)
        Me.groupBox6.Controls.Add(Me.txtData4)
        Me.groupBox6.Controls.Add(Me.txtData3)
        Me.groupBox6.Controls.Add(Me.txtData2)
        Me.groupBox6.Controls.Add(Me.txtData1)
        Me.groupBox6.Controls.Add(Me.txtData0)
        Me.groupBox6.Controls.Add(Me.nudLength)
        Me.groupBox6.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.groupBox6.Location = New System.Drawing.Point(12, 97)
        Me.groupBox6.Name = "groupBox6"
        Me.groupBox6.Size = New System.Drawing.Size(681, 79)
        Me.groupBox6.TabIndex = 56
        Me.groupBox6.TabStop = False
        Me.groupBox6.Text = "Write Messages"
        '
        'txtData6
        '
        Me.txtData6.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper
        Me.txtData6.Location = New System.Drawing.Point(512, 31)
        Me.txtData6.MaxLength = 2
        Me.txtData6.Name = "txtData6"
        Me.txtData6.Size = New System.Drawing.Size(24, 21)
        Me.txtData6.TabIndex = 28
        Me.txtData6.Text = "00"
        Me.txtData6.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txtData5
        '
        Me.txtData5.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper
        Me.txtData5.Location = New System.Drawing.Point(480, 31)
        Me.txtData5.MaxLength = 2
        Me.txtData5.Name = "txtData5"
        Me.txtData5.Size = New System.Drawing.Size(24, 21)
        Me.txtData5.TabIndex = 27
        Me.txtData5.Text = "00"
        Me.txtData5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txtData4
        '
        Me.txtData4.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper
        Me.txtData4.Location = New System.Drawing.Point(448, 31)
        Me.txtData4.MaxLength = 2
        Me.txtData4.Name = "txtData4"
        Me.txtData4.Size = New System.Drawing.Size(24, 21)
        Me.txtData4.TabIndex = 26
        Me.txtData4.Text = "00"
        Me.txtData4.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txtData3
        '
        Me.txtData3.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper
        Me.txtData3.Location = New System.Drawing.Point(416, 31)
        Me.txtData3.MaxLength = 2
        Me.txtData3.Name = "txtData3"
        Me.txtData3.Size = New System.Drawing.Size(24, 21)
        Me.txtData3.TabIndex = 25
        Me.txtData3.Text = "00"
        Me.txtData3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txtData2
        '
        Me.txtData2.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper
        Me.txtData2.Location = New System.Drawing.Point(384, 31)
        Me.txtData2.MaxLength = 2
        Me.txtData2.Name = "txtData2"
        Me.txtData2.Size = New System.Drawing.Size(24, 21)
        Me.txtData2.TabIndex = 24
        Me.txtData2.Text = "00"
        Me.txtData2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txtData1
        '
        Me.txtData1.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper
        Me.txtData1.Location = New System.Drawing.Point(352, 31)
        Me.txtData1.MaxLength = 2
        Me.txtData1.Name = "txtData1"
        Me.txtData1.Size = New System.Drawing.Size(24, 21)
        Me.txtData1.TabIndex = 23
        Me.txtData1.Text = "00"
        Me.txtData1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'txtData0
        '
        Me.txtData0.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper
        Me.txtData0.Location = New System.Drawing.Point(320, 31)
        Me.txtData0.MaxLength = 2
        Me.txtData0.Name = "txtData0"
        Me.txtData0.Size = New System.Drawing.Size(24, 21)
        Me.txtData0.TabIndex = 22
        Me.txtData0.Text = "00"
        Me.txtData0.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'nudLength
        '
        Me.nudLength.BackColor = System.Drawing.Color.White
        Me.nudLength.Location = New System.Drawing.Point(177, 31)
        Me.nudLength.Maximum = New Decimal(New Integer() {8, 0, 0, 0})
        Me.nudLength.Name = "nudLength"
        Me.nudLength.ReadOnly = True
        Me.nudLength.Size = New System.Drawing.Size(50, 21)
        Me.nudLength.TabIndex = 21
        Me.nudLength.Value = New Decimal(New Integer() {8, 0, 0, 0})
        '
        'frmM
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(712, 472)
        Me.Controls.Add(Me.groupBox1)
        Me.Controls.Add(Me.groupBox5)
        Me.Controls.Add(Me.groupBox4)
        Me.Controls.Add(Me.groupBox6)
        Me.Name = "frmM"
        Me.Text = "Form1"
        Me.groupBox1.ResumeLayout(False)
        Me.groupBox1.PerformLayout()
        Me.groupBox5.ResumeLayout(False)
        Me.groupBox4.ResumeLayout(False)
        Me.groupBox6.ResumeLayout(False)
        Me.groupBox6.PerformLayout()
        CType(Me.nudLength, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Private WithEvents chbRemote As System.Windows.Forms.CheckBox
    Private WithEvents groupBox1 As System.Windows.Forms.GroupBox
    Private WithEvents label1 As System.Windows.Forms.Label
    Private WithEvents cbbBaudrates As System.Windows.Forms.ComboBox
    Private WithEvents btnInit As System.Windows.Forms.Button
    Private WithEvents btnReset As System.Windows.Forms.Button
    Private WithEvents chbExtended As System.Windows.Forms.CheckBox
    Private WithEvents lbxInfo As System.Windows.Forms.ListBox
    Private WithEvents btnInfoClear As System.Windows.Forms.Button
    Private WithEvents btnWrite As System.Windows.Forms.Button
    Private WithEvents groupBox5 As System.Windows.Forms.GroupBox
    Private WithEvents lbxRec As System.Windows.Forms.ListBox
    Private WithEvents btnMsgClear As System.Windows.Forms.Button
    Private WithEvents label11 As System.Windows.Forms.Label
    Private WithEvents tmrRead As System.Windows.Forms.Timer
    Private WithEvents label12 As System.Windows.Forms.Label
    Private WithEvents label13 As System.Windows.Forms.Label
    Private WithEvents txtID As System.Windows.Forms.TextBox
    Private WithEvents txtData7 As System.Windows.Forms.TextBox
    Private WithEvents groupBox4 As System.Windows.Forms.GroupBox
    Private WithEvents groupBox6 As System.Windows.Forms.GroupBox
    Private WithEvents txtData6 As System.Windows.Forms.TextBox
    Private WithEvents txtData5 As System.Windows.Forms.TextBox
    Private WithEvents txtData4 As System.Windows.Forms.TextBox
    Private WithEvents txtData3 As System.Windows.Forms.TextBox
    Private WithEvents txtData2 As System.Windows.Forms.TextBox
    Private WithEvents txtData1 As System.Windows.Forms.TextBox
    Private WithEvents txtData0 As System.Windows.Forms.TextBox
    Private WithEvents nudLength As System.Windows.Forms.NumericUpDown
    Private WithEvents tmrDisplay As System.Windows.Forms.Timer
End Class
