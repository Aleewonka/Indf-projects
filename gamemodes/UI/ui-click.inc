public OnPlayerClickDynamicTextdraw(playerid, PlayerText: playertextid)
{
	MataTargetClick(playerid, PlayerText:playertextid);
	// Ponsel Key
	if(playertextid == TurnOff[playerid])
	{
		HideUiPonsel(playerid);
		CancelSelectTextDraw(playerid);
	}
	//PANEL TEXTDRAW
    if(playertextid == RP_NatunaTD[playerid][10])// Panel Buka Smartphone
	{   
		HidePanelS(playerid);
		ShowUiPonsel(playerid);
		SelectTextDraw(playerid, -1);
       	// callcmd::phone(playerid, "");
	}
	if(playertextid == RP_NatunaTD[playerid][13])// Panel Buka Identitas
	{
		HidePanelS(playerid);
		//ShowPlayerDialog(playerid, DIALOG_BAJU, DIALOG_STYLE_LIST, "Pakaian", "Perempuan\nLakiLaki", "Pilih", "Tidak");
	}
	if(playertextid == RP_NatunaTD[playerid][8])// Panel Kendaraan89 
	{
		HidePanelS(playerid);
		//ShowPlayerDialog(playerid, CAR_MENU, DIALOG_STYLE_LIST, "Car Menu", "Mesin\nBuka/Kunci Kendaraan\nBuka/Tutup Trunk\nBuka/Tutup Hood\nCek Bagasi\nLampu\nPark\nCek insu\nCek kendaraan\nNeon", "Pilih", "Tidak");
	}
	if(playertextid == RP_NatunaTD[playerid][11])// Panel Invoice
	{
		HidePanelS(playerid);
		//callcmd::mybill(playerid, "");
	}
	if(playertextid == RP_NatunaTD[playerid][7])// Panel Dokumen
	{
		HidePanelS(playerid);
		//DisplayDokumen(playerid);
	}
	if(playertextid == RP_NatunaTD[playerid][12])// Panel Action
	{
		HidePanelS(playerid);
		//InfoMsg(playerid, "Dalam tahap development.");
	}
	if (playertextid == RP_NatunaTD[playerid][9]) // Panel Inventory
	{	
		HidePanelS(playerid); // Menyembunyikan panel
		Inventory_Show(playerid); // Menampilkan inventory
	}

	if(playertextid == RP_NatunaTD[playerid][44])// Close Panel
	{
		HidePanelS(playerid);
	}
	//inventory
	for(new i = 0; i < MAX_INVENTORY; i++)
	{
		if(playertextid == BOXINV[playerid][i])
		{
			if(InventoryData[playerid][i][invExists])
			{
			    Inventory_UnSelect(playerid);
			    Inventory_Select(playerid, i);
			    new name[48];
            	strunpack(name, InventoryData[playerid][pData[playerid][pSelectItem]][invItem]);
			}
		}
	}
	if(playertextid == InventoryTD[playerid][10])
	{
		new id = pData[playerid][pSelectItem];

		if(id == -1)
		{
		    InfoMsg(playerid, "Pilih item terlebih dahulu.");
		}
		else
		{
		    if(pData[playerid][pProgress] == 1) return WarningMsg(playerid, "Anda sedang melakukan sesuatu, tunggu sampai progress selesai!!");
			new string[64];
		    strunpack(string, InventoryData[playerid][id][invItem]);

		    if(!Inventory_HasItem(playerid, string))
		    {
		   		ErrorMsg(playerid, "Item ini tidak ada di dalam inventory anda");
                Inventory_Show(playerid);
			}
			else
			{
				CallLocalFunction("OnPlayerUseItem", "dds", playerid, id, string);
			}
		}
	}
	else if(playertextid == InventoryTD[playerid][13])
	{
		Inventory_Close(playerid);
	}
	else if(playertextid == GIVETD[playerid][0])
	{
		new id = pData[playerid][pSelectItem], str[500], count = 0;
		if(id == -1)
		{
			ErrorMsg(playerid,"[Inventory] Pilih Barang Terlebih Dahulu");
		}
		else
		{
		    if (pData[playerid][pGiveAmount] < 1)
				return ErrorMsg(playerid,"[Inventory] Masukan Jumlah Terlebih Dahulu");

            foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 5) && i != playerid)
			{
				format(str, sizeof(str), "%sKantong - %s (%d)\n", str, pData[i][pName], i);
				SetPlayerListitemValue(playerid, count++, i);
			}
			if(!count) ErrorMsg(playerid, "Tidak ada player lain didekat mu!");
			else ShowPlayerDialog(playerid, DIALOG_GIVE, DIALOG_STYLE_LIST, "Hesterial - Inventory", str, "Pilih", "Tutup");
		}        
	}
	else if(playertextid == BuangItem[playerid][0])
	{
        SendClientMessage(playerid, -1, "Dalam Tahap Pengembangan.");
		// new string[64];	
		// new id = pData[playerid][pSelectItem];
		// strunpack(string, InventoryData[playerid][id][invItem]);

		// if(!strcmp(string, "Sampah")) return ErrorMsg(playerid, sprintf("Tidak dapat membuang %s sembarangan", string));
		// if(!strcmp(string, "Material")) return ErrorMsg(playerid, sprintf("Tidak dapat membuang %s sembarangan", string));
		// if(!strcmp(string, "Component")) return ErrorMsg(playerid, sprintf("Tidak dapat membuang %s sembarangan", string));
		// if(Inventory_Count(playerid, string) < pData[playerid][pGiveAmount])
		// 	return ErrorMsg(playerid, "Barang Kamu Tidak Mencukupi !");
		// if(id == -1)
		// {
		// 	ErrorMsg(playerid,"[Inventory] Pilih Barang Terlebih Dahulu");
		// }
		// else
		// {
		// 	if(pData[playerid][pGiveAmount] < 1)
		// 		return ErrorMsg(playerid,"[Inventory] Masukan Jumlah Terlebih Dahulu");           
			
		// 	DropPlayerItem(playerid, id, pData[playerid][pGiveAmount]);
		// 	BukaInven[playerid] = 1;
		// 	Inventory_Show(playerid); 
		// }                               
	}
	else if(playertextid == InventoryTD[playerid][11])
	{
		ShowPlayerDialog(playerid, DIALOG_AMOUNT, DIALOG_STYLE_INPUT, "Jumlah", "Masukan Jumlah:", "Lanjut", "Batal");
	}
	return 1;
}