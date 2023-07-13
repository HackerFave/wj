<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="12008004">
	<Item Name="我的电脑" Type="My Computer">
		<Property Name="NI.SortType" Type="Int">3</Property>
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">我的电脑/VI服务器</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">我的电脑/VI服务器</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="test_10.vi" Type="VI" URL="../test_10.vi"/>
		<Item Name="依赖关系" Type="Dependencies">
			<Item Name="CloseDevice.vi" Type="VI" URL="../CloseDevice.vi"/>
			<Item Name="ECanVci.dll" Type="Document" URL="../ECanVci.dll"/>
			<Item Name="InitCan.vi" Type="VI" URL="../InitCan.vi"/>
			<Item Name="OpenDevice.vi" Type="VI" URL="../OpenDevice.vi"/>
			<Item Name="StartCAN.vi" Type="VI" URL="../StartCAN.vi"/>
			<Item Name="Transmit.vi" Type="VI" URL="../Transmit.vi"/>
			<Item Name="ReadBoardInfo.vi" Type="VI" URL="../ReadBoardInfo.vi"/>
			<Item Name="Receive.vi" Type="VI" URL="../Receive.vi"/>
		</Item>
		<Item Name="程序生成规范" Type="Build">
			<Item Name="test_10" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{7CD4EDF7-621D-47E4-B3BF-E8AF883B876A}</Property>
				<Property Name="App_INI_GUID" Type="Str">{65521CA6-43BC-4F7E-A6D3-91B8119D3C4F}</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{13BAFDD5-FE85-4D47-B0E0-13EB83F3B694}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">test_10</Property>
				<Property Name="Bld_defaultLanguage" Type="Str">ChineseS</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../exe</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToProject</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{3C4CCB84-AF42-453E-B02A-601BF09894F4}</Property>
				<Property Name="Destination[0].destName" Type="Str">test-10.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../exe/test-10.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">relativeToProject</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">支持目录</Property>
				<Property Name="Destination[1].path" Type="Path">../exe/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">relativeToProject</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Exe_actXinfo_enumCLSID[0]" Type="Str">{E6E55CD9-AA00-405A-87A9-8437DD2B96CF}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[1]" Type="Str">{8D1083BC-941A-436D-BA3E-25417CA9995E}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[10]" Type="Str">{FFBCFB34-9D95-435A-88F9-FA3683B4895E}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[11]" Type="Str">{4A79EC8A-1C3A-4B60-9587-B560E36F3A2D}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[12]" Type="Str">{2C0446CE-D6DD-4547-B6A8-FE76851ECB08}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[13]" Type="Str">{EB5781B9-E57F-4B46-922E-8C3DCAADC3EB}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[14]" Type="Str">{EAB6D9D9-CBE7-4947-8E2C-07AD08A80BDF}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[15]" Type="Str">{CED4E1CF-7E98-4D93-81FD-F983568A425B}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[16]" Type="Str">{E1A86F06-BAA7-495E-B56A-61ECB7A4C832}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[2]" Type="Str">{17ACEEDA-9E44-4F78-BD2E-1B5508AE6D54}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[3]" Type="Str">{2803CBB1-1E9E-4EB1-8BC6-D009B91CDC62}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[4]" Type="Str">{D1A87124-E084-4C1F-9C40-48D65E428849}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[5]" Type="Str">{9FEE2652-9EDB-447A-BC83-9682DAC284EA}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[6]" Type="Str">{C2DA6281-8CB4-48A4-9033-D7331605A9B4}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[7]" Type="Str">{0B7BC021-191F-450D-81C3-518BB1AA47B8}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[8]" Type="Str">{330EC970-0330-45B6-AD62-97556839E670}</Property>
				<Property Name="Exe_actXinfo_enumCLSID[9]" Type="Str">{00C11096-5FD1-41D6-B24D-364AF0035808}</Property>
				<Property Name="Exe_actXinfo_enumCLSIDsCount" Type="Int">17</Property>
				<Property Name="Exe_actXinfo_majorVersion" Type="Int">5</Property>
				<Property Name="Exe_actXinfo_minorVersion" Type="Int">5</Property>
				<Property Name="Exe_actXinfo_objCLSID[0]" Type="Str">{B6A7CD33-3CFD-4FB3-AD4E-14C873141DD8}</Property>
				<Property Name="Exe_actXinfo_objCLSID[1]" Type="Str">{B47E7309-E616-4830-A160-3832B1C4F114}</Property>
				<Property Name="Exe_actXinfo_objCLSID[10]" Type="Str">{6AE1B402-8B41-4133-AF50-A66528F7B383}</Property>
				<Property Name="Exe_actXinfo_objCLSID[11]" Type="Str">{E6F07053-69B0-41BB-8BB5-6A4FB03BF2C2}</Property>
				<Property Name="Exe_actXinfo_objCLSID[12]" Type="Str">{BC8E6A46-9322-4E04-B751-367BB1926A6E}</Property>
				<Property Name="Exe_actXinfo_objCLSID[13]" Type="Str">{28930CCB-B439-4511-B497-B9033B80B262}</Property>
				<Property Name="Exe_actXinfo_objCLSID[2]" Type="Str">{7E1F2F40-19EC-4994-A8D8-98CCC7B20B7C}</Property>
				<Property Name="Exe_actXinfo_objCLSID[3]" Type="Str">{D86ED306-01BA-4B3E-BC96-7303E1DFEAF7}</Property>
				<Property Name="Exe_actXinfo_objCLSID[4]" Type="Str">{5860EDFD-E41B-401D-AECC-E8BAA7915CC2}</Property>
				<Property Name="Exe_actXinfo_objCLSID[5]" Type="Str">{DA8BFC9A-3A23-46B7-9408-2C9BA4DA365B}</Property>
				<Property Name="Exe_actXinfo_objCLSID[6]" Type="Str">{44E9EDC0-10DD-4D01-8146-D7692D7B1CDF}</Property>
				<Property Name="Exe_actXinfo_objCLSID[7]" Type="Str">{2B5A5BC2-2EB9-40C3-BC6C-8A79712CF831}</Property>
				<Property Name="Exe_actXinfo_objCLSID[8]" Type="Str">{C7B46AC7-2851-430F-9D8A-293ED32356BD}</Property>
				<Property Name="Exe_actXinfo_objCLSID[9]" Type="Str">{2F576991-2505-40F0-8CBD-15733D4C2FB2}</Property>
				<Property Name="Exe_actXinfo_objCLSIDsCount" Type="Int">14</Property>
				<Property Name="Exe_actXinfo_progIDPrefix" Type="Str">Test10</Property>
				<Property Name="Exe_actXServerName" Type="Str">Test10</Property>
				<Property Name="Exe_actXServerNameGUID" Type="Str"></Property>
				<Property Name="Source[0].itemID" Type="Str">{5DCF3354-A38F-4483-B3D2-CE1C93A029A2}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/我的电脑/test_10.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_fileDescription" Type="Str">test_10</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">test_10</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">版权 2015 </Property>
				<Property Name="TgtF_productName" Type="Str">test_10</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{75453A0E-F27E-4B28-BA69-9EA1B347FF02}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">test-10.exe</Property>
			</Item>
		</Item>
	</Item>
</Project>
