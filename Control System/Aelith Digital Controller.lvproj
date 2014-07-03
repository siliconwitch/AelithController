<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="13008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Differential Biasing.vi" Type="VI" URL="../Differential Biasing.vi"/>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="My C Code Generation" Type="{B877FFC9-B98B-4480-82BA-90FE4923D705}">
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{FA22820B-6958-48F9-B1A3-5273096DB5FE}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">My C Code Generation</Property>
				<Property Name="Bld_localDestDir" Type="Path">../Firmware/source/application/controller</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{8540E276-DA98-41B5-A448-B0A7B0B8E0C6}</Property>
				<Property Name="Bld_version.build" Type="Int">1</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="CCodeGen_Alignment" Type="Str">4</Property>
				<Property Name="CCodeGen_ConfigVariant" Type="Bin">%Q#!!!!!!!%!"1!$!!!"!!!!!!!!!!!!%Q!!!!F#;7&gt;&amp;&lt;G2J97Y4!)!!!!!!!1!/1#%*1GFH27ZE;7&amp;O!!%!!!!!!!!!!!!!%E.P&lt;H.U97ZU17RM&lt;W.B&gt;'FP&lt;B-!A!!!!!!"!*E!]1!!!!!!!!!"+5&amp;#8V6*8V"B:W6@1U.P:'6(:7Z@5W6U&gt;'FO:X.@17RM&lt;W.B&gt;'5O9X2M!'&gt;!&amp;Q!%#5:J=H.U)(6T:1^$&lt;WZU97FO;7ZH)'RP&lt;X!26EEA;7ZJ&gt;'FB&lt;'F[982J&lt;WY;18"Q&lt;'FD982J&lt;WYA;7ZJ&gt;'FB&lt;'F[982J&lt;WY!!"*$&lt;WZT&gt;'&amp;O&gt;%&amp;M&lt;'^D982J&lt;WY!!!%!!!!!!!!!!!!!!!!!&amp;%.P&lt;H.U97ZU2'6B&lt;'RP9W&amp;U;7^O%Q#!!!!!!!%!?1$R!!!!!!!!!!%L15*@65F@5'&amp;H:6^$1W^E:5&gt;F&lt;F^4:82U;7ZH=V^%:7&amp;M&lt;'^D982F,G.U&lt;!"&amp;1"=!!QR0&gt;81A&lt;W9A=W.P='5'6EEA:7ZE$U&amp;Q='RJ9W&amp;U;7^O)'6O:!!51W^O=X2B&lt;H2%:7&amp;M&lt;'^D982J&lt;WY!!!%!!!!!!!!!!!!!!!!!%52F=X2J&lt;G&amp;U;7^O2G^M:'6S%Q#!!!!!!!%!'E!S`````R&amp;%:8.U;7ZB&gt;'FP&lt;E:P&lt;'2F=A!"!!"16%AQ!!!!71!!!!I"1Q66=W6S=Q.397I*2'^D&gt;7VF&lt;H2T"E&gt;J&gt;%BV9B"":7RJ&gt;'B$&lt;WZU=G^M&lt;'6S#%:J=GVX98*F"H.P&gt;8*D:1NB=("M;7.B&gt;'FP&lt;AJD&lt;WZU=G^M&lt;'6S!!!!!!!!!!V%&lt;X6C&lt;'6*=U:M&lt;W&amp;U%Q#!!!!!!!%!%E!B$52P&gt;7*M:5FT2GRP981!!1!!!!!!!!!!!!!228BQ=G6T=WFP&lt;E:P&lt;'2J&lt;G=4!)!!!!!!!1!71#%228BQ=G6T=WFP&lt;E:P&lt;'2J&lt;G=!!1!!!1!!!!!!!!!72W6O:8*B&gt;'6$2H6O9X2J&lt;WZ$97RM=R-!A!!!!!!"!"R!)2:(:7ZF=G&amp;U:5.'&gt;7ZD&gt;'FP&lt;E.B&lt;'RT!!!"!!!"!!!!!!!!!"&amp;(:7ZF=G&amp;U:52F9H6H37ZG&lt;R-!A!!!!!!"!":!)2&amp;(:7ZF=G&amp;U:52F9H6H37ZG&lt;Q!"!!!!!!!!!!!!!"&amp;(:7ZF=G&amp;U:5&gt;V98*E1W^E:2-!A!!!!!!"!":!)2&amp;(:7ZF=G&amp;U:5&gt;V98*E1W^E:1!"!!!"!!!!!!!!!".(:7ZF=G&amp;U:5FO&gt;'6H:8*0&lt;GRZ%Q#!!!!!!!%!'%!B%U&gt;F&lt;G6S982F37ZU:7&gt;F=E^O&lt;(E!!1!!!!!!!!!!!!!92W6O:8*B&gt;'6-;7*S98*Z37ZU:8*G97.F%Q#!!!!!!!%!EQ$RS/.-_Q!!!!%815*@1U.P:'6(:7Z@4'FC6(FQ:3ZD&gt;'Q!=U!7!!1%4G^O:2&amp;0&lt;'1A4'FC)%FO&gt;'6S:G&amp;D:2.$)%&gt;F&lt;C"-;7)A37ZU:8*G97.F)E-A2W6O)%RJ9C"*&lt;H2F=G:B9W5A5(*F=W6S&gt;G5A5X2B&gt;'5!'%&gt;F&lt;G6S982F4'FC=G&amp;S?5FO&gt;'6S:G&amp;D:1!!!1!!!!)!!!!!!!!!%E&gt;F&lt;G6S982F5W6S;7&amp;M4WZM?2-!A!!!!!!"!"B!)2*(:7ZF=G&amp;U:6.F=GFB&lt;%^O&lt;(E!!!%!!!%!!!!!!!!!%%FO9X*F&lt;76O&gt;'&amp;M1H6J&lt;'14!)!!!!!!!1!71#%137ZD=G6N:7ZU97R#&gt;7FM:!!!!1!!!!!!!!!!!!!,476N&lt;X*Z47^E:7Q4!)!!!!!!!1!21!-!#UVF&lt;7^S?5VP:'6M!!%!!!!!!!!!!!!!!!!!"F.J&lt;'6O&gt;"-!A!!!!!!"!!R!)1:4;7RF&lt;H1!!!%!!!%!!!!!!!!!$V2B=G&gt;F&gt;%&amp;M;7&gt;O&lt;76O&gt;"-!A!!!!!!"!"6!!Q!06'&amp;S:W6U17RJ:WZN:7ZU!!%!!!!!!!1!!!!!!!!!#F2B=G&gt;F&gt;%ZB&lt;754!)!!!!!!!1!51$$`````#F2B=G&gt;F&gt;%ZB&lt;75!!!%!!!!!!!J$2W6O:8*B&gt;'^S!!!!!!!!!"&amp;6=W64&gt;'&amp;D;V:B=GFB9GRF=R-!A!!!!!!"!":!)2&amp;6=W64&gt;'&amp;D;V:B=GFB9GRF=Q!"!!!!!!!!!!!!!!JE?7ZB&lt;7FD6EFT%Q#!!!!!!!)!'E"Q!!A!!!!#!!!-&gt;GEA=G6G:8*F&lt;G.F!!!91%!!!@````]!!!JE?7ZB&lt;7FD6EFT!!!"!!%!!!!!!!!!!!</Property>
				<Property Name="CCodeGen_Endianess" Type="Str">Little endian</Property>
				<Property Name="CCodeGen_ExpressionFolding" Type="Bool">true</Property>
				<Property Name="CCodeGen_GenerateGuardCode" Type="Bool">true</Property>
				<Property Name="Destination[0].destName" Type="Str">Destination Directory</Property>
				<Property Name="Destination[0].path" Type="Path">../Firmware/source/application/controller</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../Firmware/source/application/controller/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{3DA5C90F-2847-4496-8040-C34AFE7ED020}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[0]VIProtoDir" Type="Int">1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[0]VIProtoInputIdx" Type="Int">-1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[0]VIProtoLenInput" Type="Int">-1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[0]VIProtoName" Type="Str">returnvalue</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[0]VIProtoOutputIdx" Type="Int">-1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[0]VIProtoPassBy" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[0]VIProtoVisible" Type="Bool">true</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[1]VIProtoDir" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[1]VIProtoInputIdx" Type="Int">11</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[1]VIProtoLenInput" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[1]VIProtoName" Type="Str">FrontSlip2</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[1]VIProtoOutputIdx" Type="Int">-1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[1]VIProtoPassBy" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[1]VIProtoVisible" Type="Bool">true</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[10]VIProtoDir" Type="Int">1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[10]VIProtoInputIdx" Type="Int">-1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[10]VIProtoLenInput" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[10]VIProtoName" Type="Str">WheelBR2</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[10]VIProtoOutputIdx" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[10]VIProtoPassBy" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[10]VIProtoVisible" Type="Bool">true</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[2]VIProtoDir" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[2]VIProtoInputIdx" Type="Int">10</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[2]VIProtoLenInput" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[2]VIProtoName" Type="Str">FrontPowerBias2</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[2]VIProtoOutputIdx" Type="Int">-1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[2]VIProtoPassBy" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[2]VIProtoVisible" Type="Bool">true</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[3]VIProtoDir" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[3]VIProtoInputIdx" Type="Int">9</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[3]VIProtoLenInput" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[3]VIProtoName" Type="Str">RearPowerBias2</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[3]VIProtoOutputIdx" Type="Int">-1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[3]VIProtoPassBy" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[3]VIProtoVisible" Type="Bool">true</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[4]VIProtoDir" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[4]VIProtoInputIdx" Type="Int">8</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[4]VIProtoLenInput" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[4]VIProtoName" Type="Str">RearSlip2</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[4]VIProtoOutputIdx" Type="Int">-1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[4]VIProtoPassBy" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[4]VIProtoVisible" Type="Bool">true</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[5]VIProtoDir" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[5]VIProtoInputIdx" Type="Int">7</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[5]VIProtoLenInput" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[5]VIProtoName" Type="Str">Steering2</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[5]VIProtoOutputIdx" Type="Int">-1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[5]VIProtoPassBy" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[5]VIProtoVisible" Type="Bool">true</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[6]VIProtoDir" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[6]VIProtoInputIdx" Type="Int">5</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[6]VIProtoLenInput" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[6]VIProtoName" Type="Str">Throttle2</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[6]VIProtoOutputIdx" Type="Int">-1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[6]VIProtoPassBy" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[6]VIProtoVisible" Type="Bool">true</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[7]VIProtoDir" Type="Int">1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[7]VIProtoInputIdx" Type="Int">-1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[7]VIProtoLenInput" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[7]VIProtoName" Type="Str">WheelFL2</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[7]VIProtoOutputIdx" Type="Int">3</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[7]VIProtoPassBy" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[7]VIProtoVisible" Type="Bool">true</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[8]VIProtoDir" Type="Int">1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[8]VIProtoInputIdx" Type="Int">-1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[8]VIProtoLenInput" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[8]VIProtoName" Type="Str">WheelFR2</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[8]VIProtoOutputIdx" Type="Int">2</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[8]VIProtoPassBy" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[8]VIProtoVisible" Type="Bool">true</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[9]VIProtoDir" Type="Int">1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[9]VIProtoInputIdx" Type="Int">-1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[9]VIProtoLenInput" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[9]VIProtoName" Type="Str">WheelBL2</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[9]VIProtoOutputIdx" Type="Int">1</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[9]VIProtoPassBy" Type="Int">0</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfo[9]VIProtoVisible" Type="Bool">true</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfoVIProtoConPaneCRC" Type="Int">-1700018177</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfoVIProtoFunctionName" Type="Str">DifferentialBiasing</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfoVIProtoItemCount" Type="Int">11</Property>
				<Property Name="Source[1].ExportedCGenVI.VIProtoInfoVIProtoVariant" Type="Bin">%Q#!!!!!!!I!$E!Q`````Q2O97VF!!!*1!-!!W2J=A!01!-!#'FO=(6U372Y!!!01!-!#7^V&gt;("V&gt;%FE?!!.1!-!"H"B=X.#?1!!$U!$!!BM:7Z*&lt;H"V&gt;!!!$U!$!!FM:7Z0&gt;82Q&gt;81!&amp;!"1!!=!!!!"!!)!!Q!%!!5!"A!51%!!!@````]!"Q:Q98*B&lt;8-!!"*!5!!#!!!!#!&gt;W;8"*&lt;G:P!!%!#1!!!".%;7:G:8*F&lt;H2J97R#;7&amp;T;7ZH!!!!#Q!!!!NS:82V=GZW97RV:1!!!!(``````````Q!!!!$`````!!!!!!!!!!J'=G^O&gt;&amp;.M;8!S!!!!!!!!!!P`````!!!!!!!!!!!!!!!!!!!!$U:S&lt;WZU5'^X:8*#;7&amp;T-A!!!!!!!!!+`````Q!!!!!!!!!!!!!!!!!!!!Z3:7&amp;S5'^X:8*#;7&amp;T-A!!!!!!!!!*`````Q!!!!!!!!!!!!!!!!!!!!F3:7&amp;S5WRJ=$)!!!!!!!!!#0````]!!!!!!!!!!!!!!!!!!!!*5X2F:8*J&lt;G=S!!!!!!!!!!@`````!!!!!!!!!!!!!!!!!!!!#62I=G^U&gt;'RF-A!!!!!!!!!&amp;`````Q!!!!!!!!!!!!!!!!!!!!B8;'6F&lt;%:--A!!!!(`````!!!!!Q!!!!!!!!!!!!!!!!!!!!B8;'6F&lt;%:3-A!!!!(`````!!!!!A!!!!!!!!!!!!!!!!!!!!B8;'6F&lt;%*--A!!!!(`````!!!!!1!!!!!!!!!!!!!!!!!!!!B8;'6F&lt;%*3-A!!!!(`````!!!!!!!!!!!!!!!!!!!!!!!!!!!</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Differential Biasing.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">ExportedCGenVI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
			</Item>
		</Item>
	</Item>
</Project>
