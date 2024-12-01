#define MAX_INVENTORY 				20
new PlayerText:InventoryTD[MAX_PLAYERS][16]; // done 1
new PlayerText:INV2MODELTD[MAX_PLAYERS][MAX_INVENTORY]; //done 4
new PlayerText:BERATTD[MAX_PLAYERS][MAX_INVENTORY]; // done 5
new PlayerText:INV2NAMETD[MAX_PLAYERS][MAX_INVENTORY]; //done 6
new PlayerText:AMOUNTD[MAX_PLAYERS][MAX_INVENTORY]; // done 7
new PlayerText:BOXINV[MAX_PLAYERS][MAX_INVENTORY]; // done 3
new PlayerText:BARBOX[MAX_PLAYERS][MAX_INVENTORY]; // done 8
new PlayerText:InventoryTD2[MAX_PLAYERS][3]; // done 2
new PlayerText:GIVETD[MAX_PLAYERS][3]; // done 9
new PlayerText:BuangItem[MAX_PLAYERS][2]; // done 10


//inventory
enum inventoryData
{
	invExists,
	invID,
	invItem[32 char],
	invModel,
	invQuantity,
 	invTotalQuantity
};
new InventoryData[MAX_PLAYERS][MAX_INVENTORY][inventoryData];
// new ListedInventory[MAX_PLAYERS][MAX_LISTED_ITEMS];
enum e_InventoryItems
{
	e_InventoryItem[32],
	e_InventoryModel,
	Float: e_InventoryWeight
};


// new BukaInven[MAX_PLAYERS];
new const g_aInventoryItems[][e_InventoryItems] =
{
	{"Sprunk", 19564, 0.127},
	{"Snack", 19562, 0.127},
	{"Batu", 905, 0.100},
	{"Batu_Cucian", 2936, 0.100},
	{"Emas", 19941, 0.070},
	{"Besi", 1510, 0.050},
	{"Aluminium", 19809, 0.050},
	{"Obat", 1577, 0.120},
	{"Medicine", 1579, 0.100},
	{"Jerigen", 1650, 0.125},
	{"Boombox", 2102, 0.110},
	{"Ktp", 1581, 0.500},
	{"Marijuana", 1578, 0.025},
	{"Perban", 11736, 0.030},
	{"Susu_Mentah", 1330, 0.050},
	{"Susu_Olahan", 19570, 0.080},
	{"Component", 19627, 0.100},
	{"Material", 19627, 0.100},
	{"Madualam", 2295, 0.090},
	{"Maduolahan", 1666, 0.090},	
	{"Sampah", 2840, 0.090},
	{"Botol", 1486, 0.100},
	{"MentahanOil", 2969, 0.100},
	{"RefinedOil", 2006, 0.250},
	{"Burger", 19094, 0.100},
	{"Mineral", 1455, 0.100},
	{"Nasi", 19567, 0.100},
	{"Susu", 19569, 0.100},
	{"Paket_Ayam", 19566, 0.100},
	{"Ayam_Hidup", 16776, 0.100},
	{"Ayam_Potong", 2806, 0.100},
	{"Paket_Low", 2663, 0.200},
	{"Paket_Med", 2223, 0.200},
	{"Paket_High", 2222, 0.200},
	{"MixxedOil", 19621, 0.200},
	{"Seeds", 2203, 0.070},
    {"BahanF", 19572, 0.250},
    {"BahanB", 2386, 0.100},
    {"BahanA", 2384, 0.300}
};
forward OnPlayerGiveInvItem(p1, p2, itemid, name[], value);
public OnPlayerGiveInvItem(p1, p2, itemid, name[], value)
{
	new string[500];
	strunpack(string, InventoryData[p1][itemid][invItem]);
	if(Inventory_Count(p1, string) < pData[p1][pGiveAmount])
		return ErrorMsg(p1, "Barang Kamu Tidak Mencukupi !");

	new str[528];
	if(!strcmp(name, "Snack", true)) 
	{
		//Inventory_Set(p1, InventoryData[p1][itemid][invItem], InventoryData[p1][itemid][invModel], use);
		Inventory_Set(p2, name, 19562, value);
		Inventory_Remove(p1, name, value);
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 19562, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 19562, 5);
	}
	else if(!strcmp(name, "Sprunk", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 19564, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 19564, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 19564, 5);
	}
	else if(!strcmp(name, "Batu", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 905, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 905, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 905, 5);
	}	
	else if(!strcmp(name, "Batu_Cucian", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 2936, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 2936, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 2936, 5);
	}	
	else if(!strcmp(name, "Emas", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 19941, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 19941, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 19941, 5);
	}	
	else if(!strcmp(name, "Besi", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 1510, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 1510, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 1510, 5);
	}	
	else if(!strcmp(name, "Alumunium", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 19809, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 19809, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 19809, 5);
	}	
	else if(!strcmp(name, "Obat", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 1577, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 1577, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 1577, 5);
	}	
	else if(!strcmp(name, "Medicine", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 1579, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 1579, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 1579, 5);
	}	
	else if(!strcmp(name, "Jerigen", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 1650, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 1650, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 1650, 5);
	}	
	else if(!strcmp(name, "Boombox", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 2102, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 2102, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 2102, 5);
	}	
	// else if(!strcmp(name, "Ktp", true)) 
	// {
	// 	Inventory_Remove(p1, name, value);
	// 	Inventory_Set(p2, InventoryData[p1][itemid][invItem], 1581, value);	
	// 	new strings[256], fac[24];
	// 	Info(p2, "ID-Card Otomatis tersimpan di tas selama 10 detik");
	// 	if(pData[p1][pFaction] == 1)
	// 	{
	// 		fac = "Hesterial Police";
	// 	}
	// 	else if(pData[p1][pFaction] == 2)
	// 	{
	// 		fac = "Hesterial Goverment";
	// 	}
	// 	else if(pData[p1][pFaction] == 3)
	// 	{
	// 		fac = "Hesterial Medic";
	// 	}
	// 	else if(pData[p1][pFaction] == 4)
	// 	{
	// 		fac = "Hesterial News";
	// 	}
	// 	else if(pData[p1][pFaction] == 5)
	// 	{
	// 		fac = "Hesterial Cafeteria";
	// 	}
	// 	else
	// 	{
	// 		fac = "Belum Bekerja";
	// 	}
	// 	// // Set name player
	// 	// format(strings, sizeof(strings), "%s", pData[p1][pName]);
	// 	// PlayerTextDrawSetString(p2, AsteraIDcard[p1][35], strings);
	// 	// // Set birtdate
	// 	// format(strings, sizeof(strings), "%s", pData[p1][pAge]);
	// 	// PlayerTextDrawSetString(p2, AsteraIDcard[p1][36], strings);
	// 	// // Set Job
	// 	// format(strings, sizeof(strings), "%s", fac);
	// 	// PlayerTextDrawSetString(p2, AsteraIDcard[p1][37], strings);
	// 	// // Set Expired IDCARD
	// 	// format(strings, sizeof(strings), "%s", ReturnTimelapse(gettime(), pData[p1][pIDCardTime]));
	// 	// PlayerTextDrawSetString(p2, AsteraIDcard[p1][38], strings);	
	// 	// for(new txd; txd < 39; txd++)
	// 	// {
	// 	// 	PlayerTextDrawShow(p2, AsteraIDcard[p1][txd]);
	// 	// }
	// 	// SetTimerEx("Lenzganteng", 10000, false, "ii", p2);
	// 	Inventory_Close(p1);
	
	// }	
	else if(!strcmp(name, "Marijuana", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 1578, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 1578, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 1578, 5);
	}	
	else if(!strcmp(name, "Perban", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 11736, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 11736, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 11736, 5);
	}	
	else if(!strcmp(name, "Susu_mentah", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 1330, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 1330, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 1330, 5);
	}	
	else if(!strcmp(name, "Susu_Olahan", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 19570, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 19570, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 19570, 5);
	}	
	else if(!strcmp(name, "Component", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 19627, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 19627, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 19627, 5);
	}	
	else if(!strcmp(name, "Material", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 19627, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 19627, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 19627, 5);
	}
	else if(!strcmp(name, "Madualam", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 2295, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 2295, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 2295, 5);
	}
	else if(!strcmp(name, "MaduOlahan", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 1666, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 1666, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 1666, 5);
	}
	else if(!strcmp(name, "Sampah", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 2840, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 2840, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 2840, 5);
	}
	else if(!strcmp(name, "Botol", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 1486, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 1486, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 1486, 5);
	}
	else if(!strcmp(name, "MentahanOil", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 2969, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 2969, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 2969, 5);
	}
	else if(!strcmp(name, "RefinedOil", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 2006, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 2006, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 2006, 5);
	}
	else if(!strcmp(name, "MixxedOil", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 19621, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 19621, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 19621, 5);
	}
	else if(!strcmp(name, "Burger", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 19094, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 19094, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 19094, 5);
	}
	else if(!strcmp(name, "Mineral", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 1455, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 1455, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 1455, 5);
	}
	else if(!strcmp(name, "Nasi", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 19567, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 19567, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 19567, 5);
	}
	else if(!strcmp(name, "Susu", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 19569, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 19569, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 19569, 5);
	}
	else if(!strcmp(name, "Paket_Ayam", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 19566, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 19566, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 19566, 5);
	}
	else if(!strcmp(name, "Ayam_Hidup", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 16776, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 16776, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 16776, 5);
	}
	else if(!strcmp(name, "Ayam_Potong", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 2806, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 2806, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 2806, 5);
	}
	else if(!strcmp(name, "Paket_Low", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 2663, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 2663, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 2663, 5);
	}
	else if(!strcmp(name, "Paket_Med", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 2223, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 2223, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 2223, 5);
	}
	else if(!strcmp(name, "Paket_High", true)) 
	{
		Inventory_Remove(p1, name, value);
		Inventory_Set(p2, name, 2222, value);	
		Inventory_Close(p1);
		format(str, sizeof(str), "Removed_%dx", value);
		ShowItemBox(p1, name, str, 2222, 5);
		format(str, sizeof(str), "Received_%dx", value);
		ShowItemBox(p2, name, str, 2222, 5);
	}
	else if(!strcmp(name, "Seeds", true))
	{
		ErrorMsg(p1, "Anda tidak bisa memberi seed.");
	}
	return 1;
}


forward OnPlayerUseItem(playerid, itemid, name[]);
public OnPlayerUseItem(playerid, itemid, name[])
{
	if(!strcmp(name, "Material"))
	{
	    ErrorMsg(playerid, "Item Ini Tidak Dapat Digunakan");
	}
	else if(!strcmp(name, "Component"))
	{
	    ErrorMsg(playerid, "Item Ini Tidak Dapat Digunakan");
	}
	else if(!strcmp(name, "Ayam_Potong"))
	{
	    ErrorMsg(playerid, "Item Ini Tidak Dapat Digunakan");
	}
	else if(!strcmp(name, "Ayam_Hidup"))
	{
	    ErrorMsg(playerid, "Item Ini Tidak Dapat Digunakan");
	}
	else if(!strcmp(name, "Maduolahan"))
	{
	    ErrorMsg(playerid, "Item Ini Tidak Dapat Digunakan");
	}
	else if(!strcmp(name, "Madualam"))
	{
	    ErrorMsg(playerid, "Item Ini Tidak Dapat Digunakan");
	}
	else if(!strcmp(name, "Jerigen"))
	{
	    InfoMsg(playerid, "Gunakan /gas untuk menggunakan gasfuel.");
	}
	else if(!strcmp(name, "Ktp"))
	{
	    callcmd::idcard(playerid, "");
	}
	else if(!strcmp(name, "Seeds"))
	{
		callcmd::plant(playerid, "plant");
		Inventory_Close(playerid);
	}
	else if(!strcmp(name, "Snack"))
	{
        if (PlayerData[playerid][pHunger] > 90) //ganti sesuai gm
            return Error(playerid, "You're not hungry.");

        PlayerData[playerid][pHunger] += 20; //ganti sesuai gm
		Inventory_Remove(playerid, "Snack", 1);
		Inventory_Add(playerid, "Sampah", 2840, 1);
		ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
		Inventory_Close(playerid);
        //Action(playerid, "Take Snack then eat them.");
        SetPlayerChatBubble(playerid, "> Take Snack then eat them <", COLOR_PURPLE, 30.0, 5000);				
	}
	else if(!strcmp(name, "Sprunk"))
	{
        if (PlayerData[playerid][pEnergy] > 90) //ganti sesuai gm
            return SendClientMessage(playerid, -1, "You're not thirsty.");

        PlayerData[playerid][pEnergy] += 15; //ganti sesuai gm
		Inventory_Remove(playerid, "Sprunk", 1);
		Inventory_Add(playerid, "Sampah", 2840, 1);
		ApplyAnimation(playerid, "VENDING", "VEND_DRINK2_P", 4.1, 0, 0, 0, 0, 0, 1);
		Inventory_Close(playerid);
        //Action(playerid, "Take Soft Drink then drink it.");
        SetPlayerChatBubble(playerid, "> Take Soft Drink then drink it <", COLOR_PURPLE, 30.0, 5000);		
	}	
	else if(!strcmp(name, "Nasi"))
	{
        if (PlayerData[playerid][pHunger] > 90) //ganti sesuai gm
            return Error(playerid, "You're not hungry.");

        PlayerData[playerid][pHunger] += 25; //ganti sesuai gm
		Inventory_Remove(playerid, "Nasi", 1);
		Inventory_Add(playerid, "Sampah", 2840, 1);
		ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
		Inventory_Close(playerid);
        //Action(playerid, "Take Nasi Bungkus then eat them.");
        SetPlayerChatBubble(playerid, "> Take Nasi Bungkus then eat them <", COLOR_PURPLE, 30.0, 5000);		
	}
	else if(!strcmp(name, "Burger"))
	{
        if (PlayerData[playerid][pHunger] > 90) //ganti sesuai gm
            return Error(playerid, "You're not hungry.");

        PlayerData[playerid][pHunger] += 25; //ganti sesuai gm
		Inventory_Remove(playerid, "Burger", 1);
		Inventory_Add(playerid, "Sampah", 2840, 1);
		ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
		Inventory_Close(playerid);
        //Action(playerid, "Take Burger then eat them.");
        SetPlayerChatBubble(playerid, "> Take Burger then eat them <", COLOR_PURPLE, 30.0, 5000);		
	}
	else if(!strcmp(name, "Mineral"))
	{
        if (PlayerData[playerid][pEnergy] > 90) //ganti sesuai gm
            return SendClientMessage(playerid, -1, "You're not thirsty.");

        PlayerData[playerid][pEnergy] += 15; //ganti sesuai gm
		Inventory_Remove(playerid, "Mineral", 1);
		Inventory_Add(playerid, "Sampah", 2840, 1);
		ApplyAnimation(playerid, "VENDING", "VEND_DRINK2_P", 4.1, 0, 0, 0, 0, 0, 1);
		Inventory_Close(playerid);
        //Action(playerid, "Take Mineral then drink it.");
        SetPlayerChatBubble(playerid, "> Take Mineral then drink it <", COLOR_PURPLE, 30.0, 5000);			
	}
	else if(!strcmp(name, "Susu"))
	{
        if (PlayerData[playerid][pEnergy] > 90) //ganti sesuai gm
            return SendClientMessage(playerid, -1, "You're not thirsty.");

        PlayerData[playerid][pEnergy] += 15; //ganti sesuai gm
		Inventory_Remove(playerid, "Susu", 1);
		Inventory_Add(playerid, "Sampah", 2840, 1);
		ApplyAnimation(playerid, "VENDING", "VEND_DRINK2_P", 4.1, 0, 0, 0, 0, 0, 1);
		Inventory_Close(playerid);
        //Action(playerid, "Take Susu then drink it.");
        SetPlayerChatBubble(playerid, "> Take Susu then drink it <", COLOR_PURPLE, 30.0, 5000);			
	}
	else if(!strcmp(name, "Obat"))
	{
		pData[playerid][pSick] = 0;
		pData[playerid][pBladder] = 0;
		pData[playerid][pSickTime] = 0;
		pData[playerid][pHead] = 100;
		pData[playerid][pPerut] = 100;
		pData[playerid][pRHand] = 100;
		pData[playerid][pLHand] = 100;
		pData[playerid][pRFoot] = 100;
		pData[playerid][pLFoot] = 100;
		SetPlayerDrunkLevel(playerid, 0);
		ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop",2.1,0,0,0,0,0);

		Inventory_Remove(playerid, "Obat", 1);
		Inventory_Close(playerid);
        //Action(playerid, "Take Obat then eat it.");
        SetPlayerChatBubble(playerid, "> Take Obat then eat it <", COLOR_PURPLE, 30.0, 5000);			
	}
	else if(!strcmp(name, "Medicine"))
	{
		pData[playerid][pSick] = 0;
		pData[playerid][pSickTime] = 0;
		SetPlayerDrunkLevel(playerid, 0);
		Inventory_Remove(playerid, "Medicine", 1);
		Inventory_Close(playerid);
        //Action(playerid, "Take Obat then eat it.");
        SetPlayerChatBubble(playerid, "> Take Obat then eat it <", COLOR_PURPLE, 30.0, 5000);	
		ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop",2.1,0,0,0,0,0);
	}
	else if(!strcmp(name, "Perban"))
	{
		new Float:darah;
		GetPlayerHealth(playerid, darah);
		if(pData[playerid][pHealth] > 99)
			return Error(playerid, "Max 100 Hp!");

		SetPlayerHealthEx(playerid, darah+10);
		SetPlayerDrunkLevel(playerid, 0);
		ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop",2.1,0,0,0,0,0);

		Inventory_Remove(playerid, "Perban", 1);
		Inventory_Close(playerid);
        //Action(playerid, "Take Perban then use it.");
        SetPlayerChatBubble(playerid, "> Take Perban then use it <", COLOR_PURPLE, 30.0, 5000);			
	}
	else if(!strcmp(name, "Marijuana"))
	{
		new Float:armor;
		GetPlayerArmour(playerid, armor);
		if(armor+10 > 90) return Error(playerid, "Over dosis!");

		SetPlayerArmourEx(playerid, armor+10);
		SetPlayerDrunkLevel(playerid, 4000);
		ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop",2.1,0,0,0,0,0);

		Inventory_Remove(playerid, "Marijuana", 1);
		Inventory_Close(playerid);
        //Action(playerid, "Take Marijuana then use it.");
        SetPlayerChatBubble(playerid, "> Take Marijuana then use it <", COLOR_PURPLE, 30.0, 5000);			
	}
	else if(!strcmp(name, "Paket_Low"))
	{
		Inventory_Remove(playerid, "Paket_Low", 1);
		Inventory_Add(playerid, "Sprunk", 19564, 15); 
		Inventory_Add(playerid, "Snack", 19562, 10); 
		//ShowProgressbar(playerid, "Membuka paket..", 5);

		Inventory_Close(playerid);
		ShowItemBox(playerid, "Paket_Low", "Removed_1x", 2663, 5);
		ShowItemBox(playerid, "Sprunk", "Receive_5x", 19564, 5);
		ShowItemBox(playerid, "Snack", "Receive_5x", 19562, 5);
		SetPlayerChatBubble(playerid,"Membuka paket makanannya",COLOR_PURPLE,30.0,10000);
		ApplyAnimation(playerid,"INT_HOUSE","wash_up",4.0, 1, 0, 0, 0, 0,1);				
	}
	else if(!strcmp(name, "Paket_Med"))
	{
		Inventory_Remove(playerid, "Paket_Med", 1);
		Inventory_Add(playerid, "Mineral", 1455, 10); 
		Inventory_Add(playerid, "Burger", 19094, 10); 
		//ShowProgressbar(playerid, "Membuka paket..", 5);

		Inventory_Close(playerid);
		ShowItemBox(playerid, "Paket_Med", "Removed_1x", 2223, 5);
		ShowItemBox(playerid, "Mineral", "Receive_10x", 1455, 5);
		ShowItemBox(playerid, "Burger", "Receive_10x", 19094, 5);
		SetPlayerChatBubble(playerid,"Membuka paket makanannya",COLOR_PURPLE,30.0,10000);
		ApplyAnimation(playerid,"INT_HOUSE","wash_up",4.0, 1, 0, 0, 0, 0,1);				
	}
	else if(!strcmp(name, "Paket_High"))
	{
		Inventory_Remove(playerid, "Paket_High", 1);
		Inventory_Add(playerid, "Susu", 19569, 15); 
		Inventory_Add(playerid, "Nasi", 19567, 15); 
		//ShowProgressbar(playerid, "Membuka paket..", 5);

		Inventory_Close(playerid);
		ShowItemBox(playerid, "Paket_High", "Removed_1x", 2222, 5);
		ShowItemBox(playerid, "Nasi", "Receive_15x", 19567, 5);
		ShowItemBox(playerid, "Susu", "Receive_15x", 19569, 5);
		SetPlayerChatBubble(playerid,"Membuka paket makanannya",COLOR_PURPLE,30.0,10000);
		ApplyAnimation(playerid,"INT_HOUSE","wash_up",4.0, 1, 0, 0, 0, 0,1);				
	}
	return 1;
}

stock Inventory_HasItem(playerid, item[])
{
	return (Inventory_GetItemID(playerid, item) != -1);
}

stock ResetInventoryTemp(playerid)
{
	InventoryTemp[playerid][iAmount] = 0;
	InventoryTemp[playerid][iHouseID] = -1;
	format(InventoryTemp[playerid][iItemName], 45, "_");
}

stock Inventory_Clear(playerid)
{
	static
	    string[64];

	for(new i = 0; i < MAX_INVENTORY; i++)
	{
	    if (InventoryData[playerid][i][invExists])
	    {
	        InventoryData[playerid][i][invExists] = 0;
	        InventoryData[playerid][i][invModel] = 0;
	        InventoryData[playerid][i][invQuantity] = 0;
	        InventoryData[playerid][i][invTotalQuantity] = 0;
			PlayerData[playerid][pWeight] = 0.00;
		}
	}
	format(string, sizeof(string), "DELETE FROM `inventory` WHERE `ID` = '%d'", PlayerData[playerid][pID]);
	return mysql_tquery(g_SQL, string);
}

stock Inventory_GetItemID(playerid, item[])
{
	for(new i = 0; i < MAX_INVENTORY; i++)
	{
	    if (!InventoryData[playerid][i][invExists])
	        continue;

		if (!strcmp(InventoryData[playerid][i][invItem], item)) return i;
	}
	return -1;
}

stock Inventory_GetFreeID(playerid)
{
	if (Inventory_Items(playerid) >= 20)
		return -1;

	for(new i = 0; i < MAX_INVENTORY; i++)
	{
	    if (!InventoryData[playerid][i][invExists])
	        return i;
	}
	return -1;
}

stock Inventory_Items(playerid)
{
    new count;

    for(new i = 0; i < MAX_INVENTORY; i++) if (InventoryData[playerid][i][invExists]) {
        count++;
	}
	return count;
}

stock Inventory_Count(playerid, item[])
{
	new itemid = Inventory_GetItemID(playerid, item);

	if (itemid != -1)
	    return InventoryData[playerid][itemid][invQuantity];

	return 0;
}

stock PlayerHasItem(playerid, item[])
{
	return (Inventory_GetItemID(playerid, item) != -1);
}

stock Inventory_Sets(playerid, item[], model, amount)
{
	new itemid = Inventory_GetItemID(playerid, item);

	if (itemid == -1 && amount > 0)
		Inventory_AddSets(playerid, item, model, amount);

	else if (amount > 0 && itemid != -1)
	    Inventory_SetQuantity(playerid, item, amount);

	else if (amount < 1 && itemid != -1)
	    Inventory_Remove(playerid, item, -1);

	return 1;
}

stock Inventory_AddSets(playerid, item[], model, amount = 1)
{
	new itemid = Inventory_GetItemID(playerid, item);

	if (itemid == -1)
	{
	    itemid = Inventory_GetFreeID(playerid);

	    if (itemid != -1)
	    {
	   		InventoryData[playerid][itemid][invExists] = true;
		    InventoryData[playerid][itemid][invModel] = model;
			InventoryData[playerid][itemid][invAmount] = amount;

		    strpack(InventoryData[playerid][itemid][invItem], item, 32 char);
		    return itemid;
		}
		return -1;
	}
	else
	{
		InventoryData[playerid][itemid][invAmount] += amount;
	}
	return itemid;
}

stock Inventory_AddSet(playerid, item[], model, quantity = 1, totalquantity)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		string[128];

	if (itemid == -1)
	{
	    itemid = Inventory_GetFreeID(playerid);

	    if (itemid != -1)
	    {
	        InventoryData[playerid][itemid][invExists] = true;
	        InventoryData[playerid][itemid][invModel] = model;
	        InventoryData[playerid][itemid][invQuantity] = quantity;
	        InventoryData[playerid][itemid][invTotalQuantity] = totalquantity;

	        strpack(InventoryData[playerid][itemid][invItem], item, 32 char);

            mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `inventory` (`ID`, `invItem`, `invModel`, `invQuantity`, `invTotal`) VALUES('%d', '%s', '%d', '%d', '%d')", PlayerData[playerid][pID], item, model, quantity, totalquantity);
            mysql_tquery(g_SQL, string, "OnInventoryAdd", "ii", playerid, itemid);
	        return itemid;
		}
		return -1;
	}
	else
	{
	    format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` + %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
	    mysql_tquery(g_SQL, string);

	   	format(string, sizeof(string), "UPDATE `inventory` SET `invTotal` = `invTotal` + %d WHERE `ID` = '%d' AND `invID` = '%d'", totalquantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
   		mysql_tquery(g_SQL, string);

	    InventoryData[playerid][itemid][invQuantity] += quantity;
	    InventoryData[playerid][itemid][invTotalQuantity] += totalquantity;
	}
	return itemid;
}

stock Inventory_Set(playerid, item[], model, amount)
{
    new itemid = Inventory_GetItemID(playerid, item);

    if(amount > 0)
        Inventory_Add(playerid, item, model, amount);

    else if(amount < 1 && itemid != -1)
        Inventory_Remove(playerid, item, InventoryData[playerid][itemid][invQuantity]);

    return 1;
}

stock Inventory_SetQuantity(playerid, item[], quantity)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		string[128];

	if (itemid != -1)
	{
		format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
		mysql_tquery(g_SQL, string);

		InventoryData[playerid][itemid][invQuantity] = quantity;
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
		{
			new Float:Weight = float(quantity)*g_aInventoryItems[i][e_InventoryWeight];
			PlayerData[playerid][pWeight] += Weight;
		}
	}
	return 1;
}

stock Inventory_GetInventoryID(playerid ,item[])
{
	for (new i = 0; i < MAX_INVENTORY; i ++)
	{
		if (!InventoryData[playerid][i][invExists])
			continue;

		if (!strcmp(InventoryData[playerid][i][invItem], item)) return InventoryData[playerid][i][invID];
	}
	return -1;
}

/*stock Inventory_Remove(playerid, item[], quantity = 1)
{

	new
		itemid = Inventory_GetItemID(playerid, item),
		string[300];
	
	if (itemid != -1)
	{
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
		{
			PlayerData[playerid][CountInventory] -= quantity*g_aInventoryItems[i][e_InventoryWeight];
			if(PlayerData[playerid][CountInventory] <= 0.0) PlayerData[playerid][CountInventory] = 0.0;
		}
	    if (InventoryData[playerid][itemid][invQuantity] > 0)
	    {
	        InventoryData[playerid][itemid][invQuantity] -= quantity;
		}
		if (quantity == -1 || InventoryData[playerid][itemid][invQuantity] < 1)
		{
		    InventoryData[playerid][itemid][invExists] = false;
		    InventoryData[playerid][itemid][invModel] = 0;
		    InventoryData[playerid][itemid][invQuantity] = 0;
		    strpack(InventoryData[playerid][itemid][invItem], "", 32 char);

		    mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `inventory` WHERE `ID` = '%d' AND `invID` = '%d'", PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
	        mysql_tquery(g_SQL, string);

		}
		else if (quantity != -1 && InventoryData[playerid][itemid][invQuantity] > 0)
		{
			mysql_format(g_SQL, string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` - %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
            mysql_tquery(g_SQL, string);
			
			if(PlayerData[playerid][pInventory] == 1)
			{
				PlayerTextDrawSetString(playerid, INVJUMLAH[itemid][playerid], sprintf("%d (0, 0)", InventoryData[playerid][itemid][invQuantity]));
			}
		}

		return 1;
	}
	return 0;
}*/

/*stock Inventory_Add(playerid, item[], model, quantity = 1)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		string[300];
	if(PlayerData[playerid][CountInventory] >= 50.00) {SendClientMessage(playerid, -1, "Tas kamu tidak kuat menampung lebih banyak item lagi."); return -2;}
	if (itemid == -1)
	{
	    itemid = Inventory_GetFreeID(playerid);
		if(itemid >= MAX_INVENTORY) return ErrorMsg(playerid, "Inventory mu sudah penuh");
	    if (itemid != -1)
	    {
			new Float:Weights;
			for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
			{
				Weights = float(quantity)*g_aInventoryItems[i][e_InventoryWeight];
			}
			if(PlayerData[playerid][CountInventory]+Weights >= 50.00) {SendClientMessage(playerid, -1, "Tas kamu tidak kuat menampung lebih banyak item lagi."); return 1;}
			PlayerData[playerid][CountInventory] += Weights;
	        InventoryData[playerid][itemid][invExists] = true;
	        InventoryData[playerid][itemid][invModel] = model;
	        InventoryData[playerid][itemid][invQuantity] = quantity;

	        strpack(InventoryData[playerid][itemid][invItem], item, 32 char);

			format(string, sizeof(string), "INSERT INTO `inventory` (`ID`, `invItem`, `invModel`, `invQuantity`) VALUES('%d', '%s', '%d', '%d')", PlayerData[playerid][pID], item, model, quantity);
			mysql_tquery(g_SQL, string, "OnInventoryAdd", "dd", playerid, itemid);
	        return itemid;
		}
		return -1;
	}
	else
	{
	    format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` + %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
	    mysql_tquery(g_SQL, string);

	    InventoryData[playerid][itemid][invQuantity] += quantity;
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
		{
			PlayerData[playerid][CountInventory] += quantity*g_aInventoryItems[i][e_InventoryWeight];
		}
	}
	return itemid;
}

function OnInventoryAdd(playerid, itemid)
{
	InventoryData[playerid][itemid][invID] = cache_insert_id();
	return 1;
}

function LoadPlayerItems(playerid)
{
	new name[128];
	new count = cache_num_rows();
	if(count > 0)
	{
	    forex(i, count)
	    {
	        InventoryData[playerid][i][invExists] = true;

	        cache_get_value_name_int(i, "invID", InventoryData[playerid][i][invID]);
	        cache_get_value_name_int(i, "invModel", InventoryData[playerid][i][invModel]);
	        cache_get_value_name_int(i, "invQuantity", InventoryData[playerid][i][invQuantity]);

	        cache_get_value_name(i, "invItem", name);

			strpack(InventoryData[playerid][i][invItem], name, 32 char);
		}
	}
	return 1;
}*/

stock Inventory_Remove(playerid, item[], quantity = 1)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		invid = Inventory_GetInventoryID(playerid, item),
		string[128];
    
	if (itemid != -1)
	{
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
		{
			PlayerData[playerid][pWeight] -= quantity*g_aInventoryItems[i][e_InventoryWeight];
			if(PlayerData[playerid][pWeight] <= 0.0) PlayerData[playerid][pWeight] = 0.0;
		}
		if (InventoryData[playerid][itemid][invQuantity] > 0)
		{
			InventoryData[playerid][itemid][invQuantity] -= quantity;
		}
		if (quantity == -1 || InventoryData[playerid][itemid][invQuantity] < 1)
		{
			if(!strcmp(item, "Radio", true)) {
				CallRemoteFunction("OnPlayerRemoveRadio", "d", playerid);
			}
			InventoryData[playerid][itemid][invExists] = false;
			InventoryData[playerid][itemid][invModel] = 19300;
			InventoryData[playerid][itemid][invQuantity] = 0;

			format(string, sizeof(string), "DELETE FROM `inventory` WHERE `ID` = '%d' AND `invID` = '%d'", PlayerData[playerid][pID], invid);
			mysql_tquery(g_SQL, string);
		}
		else if (quantity != -1 && InventoryData[playerid][itemid][invQuantity] > 0)
		{
			format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` - %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
			mysql_tquery(g_SQL, string);
		}
		return 1;
	}
	return 0;
}

stock Inventory_Add(playerid, item[], model, quantity = 1) //Natuna Menambahkan
{
    new
        itemid = Inventory_GetItemID(playerid, item),
        string[318];

    if(PlayerData[playerid][pWeight] >= 45) {Error(playerid, "Inventory anda sudah penuh!", 3); return -2;}
    if (itemid == -1)
    {
        itemid = Inventory_GetFreeID(playerid);

        if (itemid != -1)
        {

			if(!strcmp(item, "Radio", true)) {
				CallRemoteFunction("OnPlayerHaveRadio", "d", playerid);
			}

            new Float:Weights;
            for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
            {
                Weights = float(quantity)*g_aInventoryItems[i][e_InventoryWeight];
            }
            if(PlayerData[playerid][pWeight]+Weights >= 45) {Error(playerid, "Inventory anda sudah penuh!", 3); return 1;}
            PlayerData[playerid][pWeight] += Weights;
            InventoryData[playerid][itemid][invExists] = true;
            InventoryData[playerid][itemid][invModel] = model;
            InventoryData[playerid][itemid][invQuantity] = quantity;

            strpack(InventoryData[playerid][itemid][invItem], item, 32 char);

            mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `inventory` (`ID`, `invItem`, `invModel`, `invQuantity`) VALUES('%d', '%s', '%d', '%d')", PlayerData[playerid][pID], item, model, quantity);
            mysql_tquery(g_SQL, string, "OnInventoryAdd", "ii", playerid, itemid);
            return itemid;
        }
        return -1;
    }
    else
    {
        new Float:totalquantity = 0;
        for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true)) {
            totalquantity = g_aInventoryItems[i][e_InventoryWeight];
            break;
        }

		if(!strcmp(item, "Radio", true)) {
			CallRemoteFunction("OnPlayerHaveRadio", "d", playerid);
		}

        format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` + %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
        mysql_tquery(g_SQL, string);

        format(string, sizeof(string), "UPDATE `inventory` SET `invTotal` = `invTotal` + %d WHERE `ID` = '%d' AND `invID` = '%d'", totalquantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
        mysql_tquery(g_SQL, string);

        InventoryData[playerid][itemid][invQuantity] += quantity;
        for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
        {
            PlayerData[playerid][pWeight] += quantity*g_aInventoryItems[i][e_InventoryWeight];
        }
        printf("inventory ID: %d, DBID: %d, quantity: %d, total: %d", itemid, InventoryData[playerid][itemid][invID], quantity, totalquantity);
    }
    return itemid;
}

FUNC::OnInventoryAdd(playerid, itemid)
{
	InventoryData[playerid][itemid][invID] = cache_insert_id();
	return 1;
}

FUNC::LoadPlayerItems(playerid)
{
	new name[128];
	new count = cache_num_rows();
	if(count > 0)
	{
	    forex(i, count)
	    {
	        InventoryData[playerid][i][invExists] = true;

	        cache_get_value_name_int(i, "invID", InventoryData[playerid][i][invID]);
	        cache_get_value_name_int(i, "invModel", InventoryData[playerid][i][invModel]);
	        cache_get_value_name_int(i, "invQuantity", InventoryData[playerid][i][invQuantity]);
	        cache_get_value_name(i, "invItem", name);

			if(!strcmp(name, "Radio", true)) {
				CallRemoteFunction("OnPlayerHaveRadio", "d", playerid);
			}
			strpack(InventoryData[playerid][i][invItem], name, 32 char);
			for (new id = 0; id < sizeof(g_aInventoryItems); id ++) if(!strcmp(g_aInventoryItems[id][e_InventoryItem], InventoryData[playerid][i][invItem], true))
			{
				PlayerData[playerid][pWeight] += float(InventoryData[playerid][i][invQuantity])*g_aInventoryItems[id][e_InventoryWeight];
			}				
		}
	}
	return 1;
}

// //frisk/geledah
// stock FriskInventory(playerid, targetID)
// {
//     if (!IsPlayerConnected(playerid))
// 	    return 0;

// 	new
// 		amounts[MAX_INVENTORY],
// 		str[2012],
// 		gstr[300],
// 		string[256];

// 	format(str, sizeof(str), "Slot\tName\tAmount\n");
//     forex(i, MAX_INVENTORY)
// 	{
// 		new count;
// 	    if (!InventoryData[playerid][i][invExists])
// 	        format(str, sizeof(str), "%s{DDA0DD}#%d\t{AFAFAF}Slot Kosong\t-\n", str, i + 1);

// 		else
// 		{
// 			amounts[i] = InventoryData[playerid][i][invQuantity];
// 			strunpack(string, InventoryData[playerid][i][invItem]);
// 			format(str, sizeof(str), "%s{DDA0DD}#%d\t%s\t%d\n", str, i + 1, string, amounts[i]);
// 		}
// 		for (new ix = 0; ix < MAX_INVENTORY; ix ++) if (InventoryData[playerid][ix][invExists])
// 		{
// 			count++;
// 			format(gstr, sizeof(gstr), "{DDA0DD}Geledah (%d/%d)", count, MAX_INVENTORY);
// 		}
// 	}
// 	Dialog_Show(targetID, DialogFrisk, DIALOG_STYLE_TABLIST_HEADERS, gstr, str, "Ambil", "Keluar");
// 	return 1;
// }

// Dialog:DialogFrisk(playerid, response, listitem, inputtext[])
// {
// 	if(!response) return 1;
// 	new string[300];
// 	if(PlayerData[playerid][pFriskID] == pData[playerid][pFaction]) return ErrorMsg(playerid, "Tidak bisa mengambil paksa barang miliki fraksi");
// 	PlayerData[playerid][pListitem] = listitem;
// 	strunpack(string, InventoryData[PlayerData[playerid][pFriskID]][PlayerData[playerid][pListitem]][invItem]);

// 	Dialog_Show(playerid, FriskAmount, DIALOG_STYLE_INPUT, "Hesterial Roleplay - Jumlah Ambil", sprintf("Barang: {DDA0DD}%s{FFFFFF}\nDimiliki: {DDA0DD}(%d){FFFFFF}\nMasukan jumlah barang yang ingin kamu ambil: ", string, InventoryData[PlayerData[playerid][pFriskID]][PlayerData[playerid][pListitem]][invQuantity]), "Ambil", "Batal");
// 	return  1;
// }

// Dialog:FriskAmount(playerid, response, listitem, inputtext[])
// {
// 	if(!response) return 1;
// 	new string[300];
// 	if(!PlayerData[PlayerData[playerid][pFriskID]][pSpawned]) return ErrorMsg(playerid, "Player tidak valid");
// 	strunpack(string, InventoryData[PlayerData[playerid][pFriskID]][PlayerData[playerid][pListitem]][invItem]);

// 	if(strval(inputtext) < 0 || strval(inputtext) > 10000) return ErrorMsg(playerid, "Jumlah yang kamu masukan tidak valid");
// 	if(Inventory_Count(PlayerData[playerid][pFriskID], string) < strval(inputtext)) return ErrorMsg(playerid, "Barang yang dimiliki orang tersebut kurang");
// 	//if(IsInventoryFull(playerid, string, strval(inputtext))) return ErrorMsg(playerid, "Inventory kamu penuh");
// 	SendStaffMessage(COLOR_LENZ, "[Geledah] {DDA0DD}%s(%s) telah menggambil %s milik %s dengan jumlah %d.", ReturnName(playerid), pData[playerid][pUCP], string, ReturnName(PlayerData[playerid][pFriskID]), strval(inputtext));
// 	SendClientMessageEx(PlayerData[playerid][pFriskID], COLOR_LENZ,"[Geledah] {DDA0DD}%s(%s) telah menggambil %s milik mu dengan jumlah %d.", ReturnName(playerid), pData[playerid][pUCP], string, strval(inputtext));
// 	SendClientMessage(PlayerData[playerid][pFriskID], -1, "");
// 	SendClientMessageEx(playerid, COLOR_LENZ,"[Geledah] kamu telah menggambil %s milik %s(%s) sebanyak %d.", string, ReturnName(PlayerData[playerid][pFriskID]), ReturnAdminName(PlayerData[playerid][pFriskID]), strval(inputtext));
// 	SendClientMessage(playerid, -1, "");

// 	new dc[1000];
// 	format(dc, sizeof(dc),	"[%s] (Ucp : %s) mengambil %s milik %s dengan jumlah %d.", pData[playerid][pName], pData[playerid][pUCP], string, ReturnName(PlayerData[playerid][pFriskID]), strval(inputtext));
// 	//SendDiscordMessage(13, dc);

// 	Inventory_Add(playerid, string, InventoryData[PlayerData[playerid][pFriskID]][PlayerData[playerid][pListitem]][invModel], strval(inputtext));
// 	Inventory_Remove(PlayerData[playerid][pFriskID], string, strval(inputtext));

// 	PlayerData[playerid][pFriskID] = INVALID_PLAYER_ID;
// 	PlayerData[playerid][pListitem] = 0;
// 	return 1;
// }

// CMD:cekinv(playerid, params[])
// {
// 	if (!PlayerData[playerid][pLogged]) return ErrorMsg(playerid, "Kamu belum login.");

// 	if(pData[playerid][pAdmin] < 4)
// 		return ErrorMsg(playerid, "Anda tidak bisa akses perintah ini!");	

// 	new targetid;
// 	if(sscanf(params, "u", targetid))
// 	    return SendSyntaxMessage(playerid, "/cekinv [playerid]");

// 	if(targetid == INVALID_PLAYER_ID)
// 	    return ErrorMsg(playerid, "Invalid player id!");

// 	PlayerData[playerid][pFrisk] = true;
// 	//OpenFriskInventory(playerid, targetid);
// 	FriskInventory(targetid, playerid);
// 	return 1;
// }
CMD:agiveitem(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return ErrorMsg(playerid, "Anda tidak bisa akses perintah ini!");	
	new
	    userid,
		item[32],
		amount;

	if (sscanf(params, "uds[32]", userid, amount, item))
	    return SyntaxMsg(playerid, "/agiveitem [playerid/name] [amount] [item name]");

	for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if (!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
	{
        new id = Inventory_Set(userid, g_aInventoryItems[i][e_InventoryItem], g_aInventoryItems[i][e_InventoryModel], amount);
        if(id == -1) return ErrorMsg(playerid,  "Anda tidak memiliki slot inventory yang tersisa.");

		new dc[528];
		format(dc, sizeof(dc),  "Item Set |%s| Mengeset %s barang %s di tas berjumlah %d.", pData[playerid][pAdminname], pData[userid][pName], item, amount);
		//SendDiscordMessage(12, dc);
	}
	return 1;
}

CMD:itemlist(playerid, params[])
{
	new string[1024];
	if(pData[playerid][pAdmin] < 4)
		return ErrorMsg(playerid, "Anda tidak bisa akses perintah ini!");	
	if (!strlen(string))
	{
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++)
		{
			format(string, sizeof(string), "%s%s\n", string, g_aInventoryItems[i][e_InventoryItem]);
		}
	}
	return ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_LIST, "List of Items", string, "Select", "Cancel");
}
CMD:clearitem(playerid, params[])
{
	new targetid;
	if(pData[playerid][pAdmin] < 4)
		return ErrorMsg(playerid, "Anda tidak bisa akses perintah ini!");	

	if(sscanf(params, "u", targetid))
		return SendClientMessage(playerid, -1, "/clearitems [playerid/PartOfName]");

	if(targetid == INVALID_PLAYER_ID)
		return SendClientMessage(playerid, -1, "You have specified invalid player!");

	Inventory_Clear(targetid);
	return 1;
}

/*stock Inventory_Close(playerid)
{
	if(BukaInven[playerid] == 0) return 1;

	PlayerTextDrawHide(playerid, jumlahinven[playerid]);
	PlayerTextDrawHide(playerid, gunakaninven[playerid]);
	PlayerTextDrawHide(playerid, berikaninven[playerid]);
	PlayerTextDrawHide(playerid, buanginven[playerid]);
	PlayerTextDrawHide(playerid, closeinven[playerid]);
	CancelSelectTextDraw(playerid);
	pData[playerid][pSelectItem] = -1;
	BukaInven[playerid] = 0;
	for(new a = 0; a < 26; a++)
	{
		PlayerTextDrawHide(playerid, INVNAME[playerid][a]);
	}
	for(new i = 0; i < MAX_INVENTORY; i++)
	{
		PlayerTextDrawHide(playerid, NAMETD[playerid][i]);
		PlayerTextDrawHide(playerid, INDEXTD[playerid][i]);
		PlayerTextDrawColor(playerid, INDEXTD[playerid][i], 1296911838);
		PlayerTextDrawHide(playerid, MODELTD[playerid][i]);
		PlayerTextDrawHide(playerid, AMOUNTTD[playerid][i]);
		PlayerTextDrawHide(playerid, GARISBAWAH[playerid][i]);
	}
	return 1;
*/

/*stock Inventory_Show(playerid)
{
	if(!IsPlayerConnected(playerid))
		return 0;

	//new str[256], string[256], totalall;
	//new str[256], string[256], totalall;
	new str[256], string[256];
	format(str,1000,"%s", GetName(playerid));
	PlayerTextDrawSetString(playerid, INVNAME[playerid][13], str);
	BukaInven[playerid] = 1;
	PlayerPlaySound(playerid, 1039, 0,0,0);
	PlayerTextDrawShow(playerid, INVNAME[playerid][0]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][1]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][2]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][3]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][4]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][5]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][6]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][7]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][8]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][9]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][10]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][11]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][12]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][13]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][14]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][15]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][16]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][17]);
	PlayerTextDrawShow(playerid, jumlahinven[playerid]);
	PlayerTextDrawShow(playerid, gunakaninven[playerid]);
	PlayerTextDrawShow(playerid, berikaninven[playerid]);
	PlayerTextDrawShow(playerid, buanginven[playerid]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][18]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][19]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][20]);
	PlayerTextDrawShow(playerid, closeinven[playerid]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][21]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][22]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][23]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][24]);
	PlayerTextDrawShow(playerid, INVNAME[playerid][25]);
	SelectTextDraw(playerid, COLOR_LIME);
	for(new i = 0; i < MAX_INVENTORY; i++)
	{
		PlayerTextDrawShow(playerid, INDEXTD[playerid][i]);
		PlayerTextDrawShow(playerid, AMOUNTTD[playerid][i]);
		format(str, sizeof(str), "%.3f/50", pData[playerid][CountInventory]);
		PlayerTextDrawSetString(playerid, INVNAME[playerid][15], str);

		if(InventoryData[playerid][i][invExists])
		{
			PlayerTextDrawShow(playerid, NAMETD[playerid][i]);
			PlayerTextDrawShow(playerid, GARISBAWAH[playerid][i]);
			PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][i], InventoryData[playerid][i][invModel]);

			//sesuakian dengan object item kalian
			if(InventoryData[playerid][i][invModel] == 18867)
			{
				PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][i], -254.000000, 0.000000, 0.000000, 2.779998);
			}
			else if(InventoryData[playerid][i][invModel] == 2958)
			{
				PlayerTextDrawSetPreviewRot(playerid, NOTIFBOX[playerid][0], 0.000000, 0.000000, -85.000000, 2.029999);
			}
			else if(InventoryData[playerid][i][invModel] == 2703)
			{
				PlayerTextDrawSetPreviewRot(playerid, MODELTD[playerid][i], -80.000000, 0.000000, -12.000000, 2.779998);
			}
			PlayerTextDrawShow(playerid, MODELTD[playerid][i]);
			strunpack(string, InventoryData[playerid][i][invItem]);
			format(str, sizeof(str), "%s", string);
			PlayerTextDrawSetString(playerid, NAMETD[playerid][i], str);
			format(str, sizeof(str), "%d", InventoryData[playerid][i][invQuantity]);
			PlayerTextDrawSetString(playerid, AMOUNTTD[playerid][i], str);
		}
		else
		{
			PlayerTextDrawHide(playerid, AMOUNTTD[playerid][i]);
		}
	}
	return 1;
}*/

stock Inventory_Close(playerid) {

	Inventory_UnSelect(playerid);
    for (new i = 0; i < 3; i++) {
        PlayerTextDrawHide(playerid, InventoryTD2[playerid][i]);
    }
    for (new i = 0; i < 2; i++) {
        PlayerTextDrawHide(playerid, BuangItem[playerid][i]);
    }
    for (new i = 0; i < 13; i++) {
        PlayerTextDrawHide(playerid, InventoryTD[playerid][i]);
        PlayerTextDrawHide(playerid, InventoryTD[playerid][13]);
        PlayerTextDrawHide(playerid, InventoryTD[playerid][14]);
        PlayerTextDrawHide(playerid, InventoryTD[playerid][15]);
		PlayerData[playerid][pSelectItem] = -1;
    }
    for (new i = 0; i < MAX_INVENTORY; i++) {
        PlayerTextDrawHide(playerid, BERATTD[playerid][i]); 
        PlayerTextDrawHide(playerid, AMOUNTD[playerid][i]);
        PlayerTextDrawHide(playerid, INV2NAMETD[playerid][i]);
        PlayerTextDrawHide(playerid, INV2MODELTD[playerid][i]);
        PlayerTextDrawHide(playerid, BOXINV[playerid][i]);
        PlayerTextDrawHide(playerid, BARBOX[playerid][i]);
    }
    PlayerTextDrawHide(playerid, GIVETD[playerid][0]);
    PlayerTextDrawHide(playerid, GIVETD[playerid][1]);
    PlayerTextDrawHide(playerid, GIVETD[playerid][2]);
    CancelSelectTextDraw(playerid);
    return 1;
}

stock Inventory_Show(playerid)
{
    if(playerid != INVALID_PLAYER_ID && IsPlayerConnected(playerid))
    {
        new str[256], str2[256], string[256], strpname[256], quantitybar;
        for (new i = 0; i < 16; i++) {
            PlayerTextDrawShow(playerid, InventoryTD[playerid][i]);
        }
        for (new i = 0; i < 3; i++) {
            PlayerTextDrawShow(playerid, InventoryTD2[playerid][i]);
        }
        for (new i = 0; i < 16; i++) {
            PlayerTextDrawShow(playerid, BOXINV[playerid][i]);
        }
        for (new i = 0; i < 16; i++) {
            PlayerTextDrawShow(playerid, BARBOX[playerid][i]);
        }
        for (new i = 0; i < 2; i++) {
            PlayerTextDrawShow(playerid, BuangItem[playerid][i]);
        }
        SelectTextDraw(playerid, COLOR_GREY);
        for(new i = 0; i < MAX_INVENTORY; i++)
        {
            format(str2, sizeof(str2), "%.3f/50.00", PlayerData[playerid][pWeight]);
            PlayerTextDrawSetString(playerid, InventoryTD2[playerid][0], str2);
            PlayerTextDrawShow(playerid, InventoryTD2[playerid][0]);
            format(strpname, sizeof(strpname), "%s", GetName(playerid));
            PlayerTextDrawSetString(playerid, InventoryTD[playerid][1], strpname);
            quantitybar = floatround(PlayerData[playerid][pWeight]) * 188/48;
            PlayerTextDrawTextSize(playerid, InventoryTD2[playerid][1], quantitybar, 6.5);
            PlayerTextDrawShow(playerid, InventoryTD2[playerid][1]);
            PlayerTextDrawShow(playerid, GIVETD[playerid][0]);
            PlayerTextDrawShow(playerid, GIVETD[playerid][1]);
            PlayerTextDrawShow(playerid, GIVETD[playerid][2]);
            PlayerTextDrawShow(playerid, AMOUNTD[playerid][i]);
            PlayerTextDrawShow(playerid, InventoryTD[playerid][13]);
            PlayerTextDrawShow(playerid, InventoryTD[playerid][14]);
            PlayerTextDrawShow(playerid, InventoryTD[playerid][15]);
            //PlayerTextDrawShow(playerid, BERATTD[playerid][i]);
            if(InventoryData[playerid][i][invExists])
            {
                PlayerTextDrawShow(playerid, INV2NAMETD[playerid][i]);
                PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][i], InventoryData[playerid][i][invModel]);

                PlayerTextDrawShow(playerid, INV2MODELTD[playerid][i]);
                strunpack(string, InventoryData[playerid][i][invItem]);
                format(str, sizeof(str), "%s", string);
                PlayerTextDrawSetString(playerid, INV2NAMETD[playerid][i], str);
                format(str, sizeof(str), "%dx", InventoryData[playerid][i][invQuantity]);
                PlayerTextDrawSetString(playerid, AMOUNTD[playerid][i], str);
            // format(str, sizeof(str), "%d.0", InventoryData[playerid][i][invQuantity]);
            // PlayerTextDrawSetString(playerid, BERATTD[playerid][i], str);
            }
            else
            {
                PlayerTextDrawHide(playerid, AMOUNTD[playerid][i]);
            }
        }
    }
	return 1;
}	

stock CreatePlayerInv(playerid)
{
	//inventory by aufa
    InventoryTD[playerid][0] = CreatePlayerTextDraw(playerid, 168.000, 130.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][0], 14.000, 7.000);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][0], 1);

    InventoryTD[playerid][1] = CreatePlayerTextDraw(playerid, 165.000, 109.000, "Player");
    PlayerTextDrawLetterSize(playerid, InventoryTD[playerid][1], 0.217, 1.200);
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][1], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][1], 1);

    InventoryTD[playerid][2] = CreatePlayerTextDraw(playerid, 190.000, 130.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, InventoryTD[playerid][2], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][2], 167.500, 6.500);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][2], 673723647);
    PlayerTextDrawUseBox(playerid, InventoryTD[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, InventoryTD[playerid][2], 50);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][2], 1);

    InventoryTD[playerid][3] = CreatePlayerTextDraw(playerid, 170.000, 123.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][3], 9.000, 1.000);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][3], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][3], 1);

    InventoryTD[playerid][4] = CreatePlayerTextDraw(playerid, 180.000, 123.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][4], -1.000, 9.000);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][4], 1);

    InventoryTD[playerid][5] = CreatePlayerTextDraw(playerid, 171.000, 124.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][5], -1.000, 9.000);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][5], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][5], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][5], 1);

    InventoryTD[playerid][6] = CreatePlayerTextDraw(playerid, 379.000, 185.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, InventoryTD[playerid][6], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][6], 65.000, 160.000);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][6], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][6], 9109704);
    PlayerTextDrawUseBox(playerid, InventoryTD[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, InventoryTD[playerid][6], 50);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][6], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][6], 1);

    InventoryTD[playerid][7] = CreatePlayerTextDraw(playerid, 400.000, 234.000, "/");
    PlayerTextDrawLetterSize(playerid, InventoryTD[playerid][7], 0.418, 0.999);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][7], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][7], 1);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][7], 1);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][7], -1);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][7], 1);

    InventoryTD[playerid][8] = CreatePlayerTextDraw(playerid, 414.000, 231.000, "/");
    PlayerTextDrawLetterSize(playerid, InventoryTD[playerid][8], 0.949, 1.500);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][8], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][8], 1);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][8], 1);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][8], -1);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][8], 1);

    InventoryTD[playerid][9] = CreatePlayerTextDraw(playerid, 404.000, 234.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][9], 13.000, 3.000);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][9], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][9], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][9], 1);

    InventoryTD[playerid][10] = CreatePlayerTextDraw(playerid, 397.000, 240.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][10], 22.000, 6.000);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][10], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][10], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, InventoryTD[playerid][10], 1);

    InventoryTD[playerid][11] = CreatePlayerTextDraw(playerid, 383.000, 197.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, InventoryTD[playerid][11], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][11], 55.500, 20.000);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][11], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][11], 852308680);
    PlayerTextDrawUseBox(playerid, InventoryTD[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, InventoryTD[playerid][11], 50);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][11], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][11], 1);
    PlayerTextDrawSetSelectable(playerid, InventoryTD[playerid][11], 1);

    InventoryTD[playerid][12] = CreatePlayerTextDraw(playerid, 404.000, 237.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][12], 3.000, 3.000);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][12], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][12], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][12], 1);

    InventoryTD[playerid][13] = CreatePlayerTextDraw(playerid, 383.000, 312.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, InventoryTD[playerid][13], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][13], 55.500, 20.000);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][13], 1);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][13], 852308680);
    PlayerTextDrawUseBox(playerid, InventoryTD[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, InventoryTD[playerid][13], 50);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][13], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][13], 1);
    PlayerTextDrawSetSelectable(playerid, InventoryTD[playerid][13], 1);

    InventoryTD[playerid][14] = CreatePlayerTextDraw(playerid, 410.000, 220.000, "Use");
    PlayerTextDrawLetterSize(playerid, InventoryTD[playerid][14], 0.217, 1.200);
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][14], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][14], 2);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][14], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][14], 1);

    InventoryTD[playerid][15] = CreatePlayerTextDraw(playerid, 410.000, 315.000, "Close");
    PlayerTextDrawLetterSize(playerid, InventoryTD[playerid][15], 0.216, 1.200);
    PlayerTextDrawTextSize(playerid, InventoryTD[playerid][15], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, InventoryTD[playerid][15], 2);
    PlayerTextDrawColor(playerid, InventoryTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD[playerid][15], 255);
    PlayerTextDrawFont(playerid, InventoryTD[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, InventoryTD[playerid][15], 1);

    InventoryTD2[playerid][0] = CreatePlayerTextDraw(playerid, 210.000, 119.000, "100.00/100.00");
    PlayerTextDrawLetterSize(playerid, InventoryTD2[playerid][0], 0.143, 0.898);
    PlayerTextDrawTextSize(playerid, InventoryTD2[playerid][0], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, InventoryTD2[playerid][0], 1);
    PlayerTextDrawColor(playerid, InventoryTD2[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD2[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD2[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD2[playerid][0], 255);
    PlayerTextDrawFont(playerid, InventoryTD2[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, InventoryTD2[playerid][0], 1);

    InventoryTD2[playerid][1] = CreatePlayerTextDraw(playerid, 190.000, 130.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, InventoryTD2[playerid][1], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, InventoryTD2[playerid][1], 167.500, 6.500);
    PlayerTextDrawAlignment(playerid, InventoryTD2[playerid][1], 1);
    PlayerTextDrawColor(playerid, InventoryTD2[playerid][1], 852308680);
    PlayerTextDrawUseBox(playerid, InventoryTD2[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, InventoryTD2[playerid][1], 50);
    PlayerTextDrawSetShadow(playerid, InventoryTD2[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD2[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD2[playerid][1], 255);
    PlayerTextDrawFont(playerid, InventoryTD2[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, InventoryTD2[playerid][1], 1);

    InventoryTD2[playerid][2] = CreatePlayerTextDraw(playerid, 192.000, 117.000, "Berat:");
    PlayerTextDrawLetterSize(playerid, InventoryTD2[playerid][2], 0.165, 1.098);
    PlayerTextDrawTextSize(playerid, InventoryTD2[playerid][2], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, InventoryTD2[playerid][2], 1);
    PlayerTextDrawColor(playerid, InventoryTD2[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, InventoryTD2[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, InventoryTD2[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, InventoryTD2[playerid][2], 255);
    PlayerTextDrawFont(playerid, InventoryTD2[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, InventoryTD2[playerid][2], 1);

    BOXINV[playerid][0] = CreatePlayerTextDraw(playerid, 165.000, 144.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][0], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][0], 46.000, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][0], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][0], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][0], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][0], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][0], 1);

    BOXINV[playerid][1] = CreatePlayerTextDraw(playerid, 214.000, 144.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][1], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][1], 46.000, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][1], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][1], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][1], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][1], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][1], 1);

    BOXINV[playerid][2] = CreatePlayerTextDraw(playerid, 262.000, 144.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][2], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][2], 46.000, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][2], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][2], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][2], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][2], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][2], 1);

    BOXINV[playerid][3] = CreatePlayerTextDraw(playerid, 311.000, 144.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][3], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][3], 46.500, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][3], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][3], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][3], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][3], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][3], 1);

    BOXINV[playerid][4] = CreatePlayerTextDraw(playerid, 165.000, 214.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][4], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][4], 46.000, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][4], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][4], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][4], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][4], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][4], 1);

    BOXINV[playerid][5] = CreatePlayerTextDraw(playerid, 214.000, 214.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][5], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][5], 46.000, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][5], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][5], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][5], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][5], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][5], 1);

    BOXINV[playerid][6] = CreatePlayerTextDraw(playerid, 262.000, 214.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][6], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][6], 46.000, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][6], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][6], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][6], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][6], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][6], 1);

    BOXINV[playerid][7] = CreatePlayerTextDraw(playerid, 311.000, 214.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][7], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][7], 46.500, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][7], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][7], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][7], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][7], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][7], 1);

    BOXINV[playerid][8] = CreatePlayerTextDraw(playerid, 165.000, 283.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][8], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][8], 46.000, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][8], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][8], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][8], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][8], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][8], 1);

    BOXINV[playerid][9] = CreatePlayerTextDraw(playerid, 214.000, 283.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][9], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][9], 46.000, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][9], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][9], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][9], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][9], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][9], 1);

    BOXINV[playerid][10] = CreatePlayerTextDraw(playerid, 262.000, 283.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][10], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][10], 46.000, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][10], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][10], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][10], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][10], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][10], 1);

    BOXINV[playerid][11] = CreatePlayerTextDraw(playerid, 311.000, 283.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][11], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][11], 46.500, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][11], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][11], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][11], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][11], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][11], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][11], 1);

    BOXINV[playerid][12] = CreatePlayerTextDraw(playerid, 165.000, 352.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][12], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][12], 46.000, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][12], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][12], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][12], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][12], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][12], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][12], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][12], 1);

    BOXINV[playerid][13] = CreatePlayerTextDraw(playerid, 214.000, 352.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][13], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][13], 46.000, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][13], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][13], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][13], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][13], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][13], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][13], 1);

    BOXINV[playerid][14] = CreatePlayerTextDraw(playerid, 262.000, 352.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][14], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][14], 46.000, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][14], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][14], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][14], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][14], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][14], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][14], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][14], 1);

    BOXINV[playerid][15] = CreatePlayerTextDraw(playerid, 311.000, 352.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BOXINV[playerid][15], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BOXINV[playerid][15], 46.500, 64.000);
    PlayerTextDrawAlignment(playerid, BOXINV[playerid][15], 1);
    PlayerTextDrawColor(playerid, BOXINV[playerid][15], 9109704);
    PlayerTextDrawUseBox(playerid, BOXINV[playerid][15], 1);
    PlayerTextDrawBoxColor(playerid, BOXINV[playerid][15], 50);
    PlayerTextDrawSetShadow(playerid, BOXINV[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, BOXINV[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, BOXINV[playerid][15], 255);
    PlayerTextDrawFont(playerid, BOXINV[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, BOXINV[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, BOXINV[playerid][15], 1);
    
    INV2MODELTD[playerid][0] = CreatePlayerTextDraw(playerid, 132.000, 99.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][0], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][0], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][0], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][0], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][0], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][0], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][0], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][0], 1, 1);

    INV2MODELTD[playerid][1] = CreatePlayerTextDraw(playerid, 180.000, 99.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][1], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][1], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][1], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][1], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][1], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][1], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][1], 0, 0);

    INV2MODELTD[playerid][2] = CreatePlayerTextDraw(playerid, 228.000, 99.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][2], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][2], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][2], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][2], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][2], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][2], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][2], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][2], 1, 1);

    INV2MODELTD[playerid][3] = CreatePlayerTextDraw(playerid, 277.000, 99.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][3], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][3], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][3], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][3], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][3], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][3], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][3], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][3], 1, 1);

    INV2MODELTD[playerid][4] = CreatePlayerTextDraw(playerid, 132.000, 169.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][4], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][4], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][4], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][4], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][4], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][4], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][4], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][4], 1, 1);

    INV2MODELTD[playerid][5] = CreatePlayerTextDraw(playerid, 179.000, 169.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][5], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][5], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][5], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][5], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][5], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][5], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][5], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][5], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][5], 1, 1);

    INV2MODELTD[playerid][6] = CreatePlayerTextDraw(playerid, 227.000, 169.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][6], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][6], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][6], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][6], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][6], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][6], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][6], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][6], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][6], 1, 1);

    INV2MODELTD[playerid][7] = CreatePlayerTextDraw(playerid, 276.000, 169.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][7], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][7], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][7], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][7], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][7], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][7], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][7], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][7], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][7], 1, 1);

    INV2MODELTD[playerid][8] = CreatePlayerTextDraw(playerid, 132.000, 238.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][8], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][8], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][8], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][8], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][8], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][8], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][8], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][8], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][8], 1, 1);

    INV2MODELTD[playerid][9] = CreatePlayerTextDraw(playerid, 178.000, 238.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][9], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][9], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][9], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][9], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][9], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][9], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][9], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][9], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][9], 1, 1);

    INV2MODELTD[playerid][10] = CreatePlayerTextDraw(playerid, 226.000, 238.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][10], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][10], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][10], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][10], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][10], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][10], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][10], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][10], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][10], 1, 1);

    INV2MODELTD[playerid][11] = CreatePlayerTextDraw(playerid, 276.000, 238.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][11], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][11], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][11], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][11], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][11], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][11], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][11], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][11], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][11], 1, 1);

    INV2MODELTD[playerid][12] = CreatePlayerTextDraw(playerid, 132.000, 310.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][12], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][12], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][12], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][12], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][12], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][12], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][12], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][12], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][12], 0, 0);

    INV2MODELTD[playerid][13] = CreatePlayerTextDraw(playerid, 178.000, 310.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][13], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][13], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][13], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][13], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][13], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][13], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][13], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][13], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][13], 1, 1);

    INV2MODELTD[playerid][14] = CreatePlayerTextDraw(playerid, 227.000, 310.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][14], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][14], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][14], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][14], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][14], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][14], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][14], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][14], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][14], 1, 1);

    INV2MODELTD[playerid][15] = CreatePlayerTextDraw(playerid, 276.000, 310.000, "Preview_Model");
    PlayerTextDrawLetterSize(playerid, INV2MODELTD[playerid][15], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, INV2MODELTD[playerid][15], 112.500, 150.000);
    PlayerTextDrawAlignment(playerid, INV2MODELTD[playerid][15], 1);
    PlayerTextDrawColor(playerid, INV2MODELTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, INV2MODELTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, INV2MODELTD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2MODELTD[playerid][15], 0);
    PlayerTextDrawFont(playerid, INV2MODELTD[playerid][15], 5);
    PlayerTextDrawSetProportional(playerid, INV2MODELTD[playerid][15], 1);
    PlayerTextDrawSetPreviewModel(playerid, INV2MODELTD[playerid][15], 2663);
    PlayerTextDrawSetPreviewRot(playerid, INV2MODELTD[playerid][15], -10.000, 0.000, -20.000, 3.229);
    PlayerTextDrawSetPreviewVehCol(playerid, INV2MODELTD[playerid][15], 1, 1);

    BERATTD[playerid][0] = CreatePlayerTextDraw(playerid, 203.000, 199.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][0], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][0], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][0], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][0], 1);

    BERATTD[playerid][1] = CreatePlayerTextDraw(playerid, 251.000, 199.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][1], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][1], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][1], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][1], 1);

    BERATTD[playerid][2] = CreatePlayerTextDraw(playerid, 299.000, 199.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][2], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][2], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][2], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][2], 1);

    BERATTD[playerid][3] = CreatePlayerTextDraw(playerid, 349.000, 199.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][3], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][3], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][3], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][3], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][3], 1);

    BERATTD[playerid][4] = CreatePlayerTextDraw(playerid, 203.000, 270.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][4], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][4], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][4], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][4], 1);

    BERATTD[playerid][5] = CreatePlayerTextDraw(playerid, 251.000, 270.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][5], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][5], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][5], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][5], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][5], 1);

    BERATTD[playerid][6] = CreatePlayerTextDraw(playerid, 299.000, 270.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][6], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][6], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][6], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][6], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][6], 1);

    BERATTD[playerid][7] = CreatePlayerTextDraw(playerid, 349.000, 270.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][7], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][7], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][7], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][7], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][7], 1);

    BERATTD[playerid][8] = CreatePlayerTextDraw(playerid, 202.000, 339.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][8], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][8], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][8], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][8], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][8], 1);

    BERATTD[playerid][9] = CreatePlayerTextDraw(playerid, 251.000, 339.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][9], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][9], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][9], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][9], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][9], 1);

    BERATTD[playerid][10] = CreatePlayerTextDraw(playerid, 299.000, 339.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][10], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][10], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][10], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][10], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][10], 1);

    BERATTD[playerid][11] = CreatePlayerTextDraw(playerid, 349.000, 339.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][11], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][11], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][11], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][11], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][11], 1);

    BERATTD[playerid][12] = CreatePlayerTextDraw(playerid, 202.000, 408.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][12], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][12], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][12], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][12], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][12], 1);

    BERATTD[playerid][13] = CreatePlayerTextDraw(playerid, 249.000, 408.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][13], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][13], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][13], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][13], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][13], 1);

    BERATTD[playerid][14] = CreatePlayerTextDraw(playerid, 300.000, 408.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][14], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][14], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][14], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][14], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][14], 1);

    BERATTD[playerid][15] = CreatePlayerTextDraw(playerid, 348.000, 408.000, "0.0");
    PlayerTextDrawLetterSize(playerid, BERATTD[playerid][15], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, BERATTD[playerid][15], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BERATTD[playerid][15], 2);
    PlayerTextDrawColor(playerid, BERATTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, BERATTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, BERATTD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, BERATTD[playerid][15], 255);
    PlayerTextDrawFont(playerid, BERATTD[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, BERATTD[playerid][15], 1);

    INV2NAMETD[playerid][0] = CreatePlayerTextDraw(playerid, 167.000, 146.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][0], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][0], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][0], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][0], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][0], 1);

    INV2NAMETD[playerid][1] = CreatePlayerTextDraw(playerid, 215.000, 146.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][1], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][1], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][1], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][1], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][1], 1);

    INV2NAMETD[playerid][2] = CreatePlayerTextDraw(playerid, 264.000, 146.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][2], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][2], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][2], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][2], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][2], 1);

    INV2NAMETD[playerid][3] = CreatePlayerTextDraw(playerid, 313.000, 146.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][3], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][3], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][3], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][3], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][3], 1);

    INV2NAMETD[playerid][4] = CreatePlayerTextDraw(playerid, 167.000, 215.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][4], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][4], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][4], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][4], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][4], 1);

    INV2NAMETD[playerid][5] = CreatePlayerTextDraw(playerid, 216.000, 215.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][5], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][5], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][5], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][5], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][5], 1);

    INV2NAMETD[playerid][6] = CreatePlayerTextDraw(playerid, 264.000, 215.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][6], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][6], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][6], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][6], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][6], 1);

    INV2NAMETD[playerid][7] = CreatePlayerTextDraw(playerid, 313.000, 215.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][7], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][7], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][7], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][7], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][7], 1);

    INV2NAMETD[playerid][8] = CreatePlayerTextDraw(playerid, 167.000, 284.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][8], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][8], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][8], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][8], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][8], 1);

    INV2NAMETD[playerid][9] = CreatePlayerTextDraw(playerid, 216.000, 284.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][9], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][9], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][9], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][9], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][9], 1);

    INV2NAMETD[playerid][10] = CreatePlayerTextDraw(playerid, 264.000, 284.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][10], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][10], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][10], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][10], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][10], 1);

    INV2NAMETD[playerid][11] = CreatePlayerTextDraw(playerid, 314.000, 284.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][11], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][11], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][11], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][11], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][11], 1);

    INV2NAMETD[playerid][12] = CreatePlayerTextDraw(playerid, 167.000, 354.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][12], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][12], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][12], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][12], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][12], 1);

    INV2NAMETD[playerid][13] = CreatePlayerTextDraw(playerid, 216.000, 354.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][13], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][13], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][13], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][13], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][13], 1);

    INV2NAMETD[playerid][14] = CreatePlayerTextDraw(playerid, 264.000, 354.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][14], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][14], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][14], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][14], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][14], 1);

    INV2NAMETD[playerid][15] = CreatePlayerTextDraw(playerid, 313.000, 354.000, "Nama Barang");
    PlayerTextDrawLetterSize(playerid, INV2NAMETD[playerid][15], 0.136, 0.898);
    PlayerTextDrawTextSize(playerid, INV2NAMETD[playerid][15], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, INV2NAMETD[playerid][15], 1);
    PlayerTextDrawColor(playerid, INV2NAMETD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, INV2NAMETD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, INV2NAMETD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, INV2NAMETD[playerid][15], 255);
    PlayerTextDrawFont(playerid, INV2NAMETD[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, INV2NAMETD[playerid][15], 1);

    AMOUNTD[playerid][0] = CreatePlayerTextDraw(playerid, 167.000, 199.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][0], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][0], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][0], 1);

    AMOUNTD[playerid][1] = CreatePlayerTextDraw(playerid, 215.000, 199.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][1], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][1], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][1], 1);

    AMOUNTD[playerid][2] = CreatePlayerTextDraw(playerid, 264.000, 199.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][2], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][2], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][2], 1);

    AMOUNTD[playerid][3] = CreatePlayerTextDraw(playerid, 314.000, 199.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][3], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][3], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][3], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][3], 1);

    AMOUNTD[playerid][4] = CreatePlayerTextDraw(playerid, 167.000, 270.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][4], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][4], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][4], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][4], 1);

    AMOUNTD[playerid][5] = CreatePlayerTextDraw(playerid, 215.000, 270.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][5], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][5], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][5], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][5], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][5], 1);

    AMOUNTD[playerid][6] = CreatePlayerTextDraw(playerid, 265.000, 270.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][6], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][6], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][6], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][6], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][6], 1);

    AMOUNTD[playerid][7] = CreatePlayerTextDraw(playerid, 313.000, 270.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][7], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][7], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][7], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][7], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][7], 1);

    AMOUNTD[playerid][8] = CreatePlayerTextDraw(playerid, 167.000, 338.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][8], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][8], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][8], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][8], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][8], 1);

    AMOUNTD[playerid][9] = CreatePlayerTextDraw(playerid, 216.000, 338.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][9], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][9], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][9], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][9], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][9], 1);

    AMOUNTD[playerid][10] = CreatePlayerTextDraw(playerid, 264.000, 338.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][10], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][10], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][10], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][10], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][10], 1);

    AMOUNTD[playerid][11] = CreatePlayerTextDraw(playerid, 313.000, 338.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][11], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][11], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][11], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][11], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][11], 1);

    AMOUNTD[playerid][12] = CreatePlayerTextDraw(playerid, 167.000, 408.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][12], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][12], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][12], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][12], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][12], 1);

    AMOUNTD[playerid][13] = CreatePlayerTextDraw(playerid, 216.000, 408.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][13], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][13], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][13], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][13], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][13], 1);

    AMOUNTD[playerid][14] = CreatePlayerTextDraw(playerid, 265.000, 408.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][14], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][14], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][14], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][14], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][14], 1);

    AMOUNTD[playerid][15] = CreatePlayerTextDraw(playerid, 314.000, 408.000, "1x");
    PlayerTextDrawLetterSize(playerid, AMOUNTD[playerid][15], 0.137, 0.699);
    PlayerTextDrawTextSize(playerid, AMOUNTD[playerid][15], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, AMOUNTD[playerid][15], 1);
    PlayerTextDrawColor(playerid, AMOUNTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, AMOUNTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, AMOUNTD[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, AMOUNTD[playerid][15], 255);
    PlayerTextDrawFont(playerid, AMOUNTD[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, AMOUNTD[playerid][15], 1);

    BARBOX[playerid][0] = CreatePlayerTextDraw(playerid, 165.000, 205.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][0], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][0], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][0], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][0], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][0], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][0], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][0], 1);

    BARBOX[playerid][1] = CreatePlayerTextDraw(playerid, 214.000, 205.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][1], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][1], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][1], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][1], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][1], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][1], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][1], 1);

    BARBOX[playerid][2] = CreatePlayerTextDraw(playerid, 262.000, 205.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][2], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][2], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][2], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][2], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][2], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][2], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][2], 1);

    BARBOX[playerid][3] = CreatePlayerTextDraw(playerid, 311.000, 205.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][3], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][3], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][3], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][3], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][3], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][3], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][3], 1);

    BARBOX[playerid][4] = CreatePlayerTextDraw(playerid, 165.000, 275.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][4], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][4], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][4], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][4], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][4], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][4], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][4], 1);

    BARBOX[playerid][5] = CreatePlayerTextDraw(playerid, 214.000, 275.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][5], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][5], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][5], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][5], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][5], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][5], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][5], 1);

    BARBOX[playerid][6] = CreatePlayerTextDraw(playerid, 262.000, 275.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][6], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][6], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][6], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][6], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][6], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][6], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][6], 1);

    BARBOX[playerid][7] = CreatePlayerTextDraw(playerid, 311.000, 275.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][7], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][7], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][7], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][7], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][7], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][7], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][7], 1);

    BARBOX[playerid][8] = CreatePlayerTextDraw(playerid, 165.000, 344.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][8], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][8], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][8], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][8], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][8], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][8], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][8], 1);

    BARBOX[playerid][9] = CreatePlayerTextDraw(playerid, 214.000, 344.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][9], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][9], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][9], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][9], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][9], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][9], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][9], 1);

    BARBOX[playerid][10] = CreatePlayerTextDraw(playerid, 262.000, 344.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][10], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][10], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][10], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][10], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][10], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][10], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][10], 1);

    BARBOX[playerid][11] = CreatePlayerTextDraw(playerid, 311.000, 344.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][11], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][11], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][11], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][11], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][11], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][11], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][11], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][11], 1);

    BARBOX[playerid][12] = CreatePlayerTextDraw(playerid, 165.000, 413.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][12], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][12], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][12], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][12], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][12], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][12], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][12], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][12], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][12], 1);

    BARBOX[playerid][13] = CreatePlayerTextDraw(playerid, 214.000, 413.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][13], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][13], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][13], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][13], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][13], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][13], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][13], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][13], 1);

    BARBOX[playerid][14] = CreatePlayerTextDraw(playerid, 262.000, 413.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][14], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][14], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][14], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][14], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][14], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][14], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][14], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][14], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][14], 1);

    BARBOX[playerid][15] = CreatePlayerTextDraw(playerid, 311.000, 413.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BARBOX[playerid][15], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BARBOX[playerid][15], 46.000, 3.000);
    PlayerTextDrawAlignment(playerid, BARBOX[playerid][15], 1);
    PlayerTextDrawColor(playerid, BARBOX[playerid][15], 852308680);
    PlayerTextDrawUseBox(playerid, BARBOX[playerid][15], 1);
    PlayerTextDrawBoxColor(playerid, BARBOX[playerid][15], 50);
    PlayerTextDrawSetShadow(playerid, BARBOX[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, BARBOX[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, BARBOX[playerid][15], 255);
    PlayerTextDrawFont(playerid, BARBOX[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, BARBOX[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, BARBOX[playerid][15], 1);

    GIVETD[playerid][0] = CreatePlayerTextDraw(playerid, 383.000, 256.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, GIVETD[playerid][0], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, GIVETD[playerid][0], 55.500, 20.000);
    PlayerTextDrawAlignment(playerid, GIVETD[playerid][0], 1);
    PlayerTextDrawColor(playerid, GIVETD[playerid][0], 852308680);
    PlayerTextDrawUseBox(playerid, GIVETD[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, GIVETD[playerid][0], 50);
    PlayerTextDrawSetShadow(playerid, GIVETD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, GIVETD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, GIVETD[playerid][0], 255);
    PlayerTextDrawFont(playerid, GIVETD[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, GIVETD[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, GIVETD[playerid][0], 1);

    GIVETD[playerid][1] = CreatePlayerTextDraw(playerid, 410.000, 260.000, "Give");
    PlayerTextDrawLetterSize(playerid, GIVETD[playerid][1], 0.220, 1.200);
    PlayerTextDrawTextSize(playerid, GIVETD[playerid][1], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, GIVETD[playerid][1], 2);
    PlayerTextDrawColor(playerid, GIVETD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, GIVETD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, GIVETD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, GIVETD[playerid][1], 255);
    PlayerTextDrawFont(playerid, GIVETD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, GIVETD[playerid][1], 1);

    GIVETD[playerid][2] = CreatePlayerTextDraw(playerid, 408.000, 201.000, "0");
    PlayerTextDrawLetterSize(playerid, GIVETD[playerid][2], 0.219, 1.200);
    PlayerTextDrawTextSize(playerid, GIVETD[playerid][2], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, GIVETD[playerid][2], 2);
    PlayerTextDrawColor(playerid, GIVETD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, GIVETD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, GIVETD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, GIVETD[playerid][2], 255);
    PlayerTextDrawFont(playerid, GIVETD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, GIVETD[playerid][2], 1);

    BuangItem[playerid][0] = CreatePlayerTextDraw(playerid, 383.000, 284.000, "ld_bum:blkdot");
    PlayerTextDrawLetterSize(playerid, BuangItem[playerid][0], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, BuangItem[playerid][0], 55.500, 20.000);
    PlayerTextDrawAlignment(playerid, BuangItem[playerid][0], 1);
    PlayerTextDrawColor(playerid, BuangItem[playerid][0], 852308680);
    PlayerTextDrawUseBox(playerid, BuangItem[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, BuangItem[playerid][0], 50);
    PlayerTextDrawSetShadow(playerid, BuangItem[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, BuangItem[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, BuangItem[playerid][0], 255);
    PlayerTextDrawFont(playerid, BuangItem[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, BuangItem[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, BuangItem[playerid][0], 1);

    BuangItem[playerid][1] = CreatePlayerTextDraw(playerid, 410.000, 286.000, "Drop");
    PlayerTextDrawLetterSize(playerid, BuangItem[playerid][1], 0.218, 1.200);
    PlayerTextDrawTextSize(playerid, BuangItem[playerid][1], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, BuangItem[playerid][1], 2);
    PlayerTextDrawColor(playerid, BuangItem[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, BuangItem[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, BuangItem[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, BuangItem[playerid][1], 255);
    PlayerTextDrawFont(playerid, BuangItem[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, BuangItem[playerid][1], 1);
	return 1;
}

stock Inventory_Update(playerid)
{
	if(!IsPlayerConnected(playerid))
		return 0;

	new str[256], str2[200], string[256], quantitybar;
	for(new i = 0; i < MAX_INVENTORY; i++)
	{
		format(str2, sizeof(str2), "%.3f/50.00", PlayerData[playerid][pWeight]);
		PlayerTextDrawSetString(playerid, InventoryTD2[playerid][0], str2);
		quantitybar = floatround(PlayerData[playerid][pWeight]) * 188/48;
	    PlayerTextDrawTextSize(playerid, InventoryTD2[playerid][1], quantitybar, 6.5);
		if(InventoryData[playerid][i][invExists])
		{
            strunpack(string, InventoryData[playerid][i][invItem]);
            format(str, sizeof(str), "%s", string);
            PlayerTextDrawSetString(playerid, INV2NAMETD[playerid][i], str);
            format(str, sizeof(str), "%dx", InventoryData[playerid][i][invQuantity]);
            PlayerTextDrawSetString(playerid, AMOUNTD[playerid][i], str);
           // format(str, sizeof(str), "%d.0", InventoryData[playerid][i][invQuantity]);
           // PlayerTextDrawSetString(playerid, BERATTD[playerid][i], str);
		}
		else
		{
            PlayerTextDrawHide(playerid, AMOUNTD[playerid][i]);
            //PlayerTextDrawHide(playerid, BERATTD[playerid][i]);
            PlayerTextDrawHide(playerid, INV2MODELTD[playerid][i]);
            PlayerTextDrawHide(playerid, INV2NAMETD[playerid][i]);
            PlayerTextDrawHide(playerid, BARBOX[playerid][i]);
		}
	}
	return 1;
}

/*stock Inventory_Update(playerid)
{
	new str[256], string[256];
	for(new i = 0; i < MAX_INVENTORY; i++)
	{
		format(str, sizeof(str), "%.3f/50.00", pData[playerid][CountInventory]);
		PlayerTextDrawSetString(playerid, INVNAME[playerid][15], str);
		if(InventoryData[playerid][i][invExists])
		{
			//sesuakian dengan object item kalian
			strunpack(string, InventoryData[playerid][i][invItem]);
			format(str, sizeof(str), "%s", string);
			PlayerTextDrawSetString(playerid, NAMETD[playerid][i], str);
			format(str, sizeof(str), "%d", InventoryData[playerid][i][invQuantity]);
			PlayerTextDrawSetString(playerid, AMOUNTTD[playerid][i], str);
		}
		else
		{
			PlayerTextDrawHide(playerid, AMOUNTTD[playerid][i]);
			PlayerTextDrawHide(playerid, MODELTD[playerid][i]);
			PlayerTextDrawHide(playerid, NAMETD[playerid][i]);
		}
	}
}*/

/*stock MenuStore_SelectRow(playerid, row)
{
	pData[playerid][pSelectItem] = row;
    PlayerTextDrawHide(playerid,INDEXTD[playerid][row]);
	PlayerTextDrawColor(playerid, INDEXTD[playerid][row], 16777215);
	PlayerTextDrawShow(playerid,INDEXTD[playerid][row]);
}

stock MenuStore_UnselectRow(playerid)
{
	if(pData[playerid][pSelectItem] != -1)
	{
		new row = pData[playerid][pSelectItem];
		PlayerTextDrawHide(playerid,INDEXTD[playerid][row]);
		PlayerTextDrawColor(playerid, INDEXTD[playerid][row], 1296911838);
		PlayerTextDrawShow(playerid,INDEXTD[playerid][row]);
	}

	pData[playerid][pSelectItem] = -1;
}*/

stock Inventory_Select(playerid, row)
{
	PlayerData[playerid][pSelectItem] = row;
    PlayerTextDrawHide(playerid,BOXINV[playerid][row]);
	PlayerTextDrawColor(playerid, BOXINV[playerid][row], X11_GREY);
	PlayerTextDrawShow(playerid,BOXINV[playerid][row]);
}

stock Inventory_UnSelect(playerid)
{
	if(PlayerData[playerid][pSelectItem] != -1)
	{
		new row = PlayerData[playerid][pSelectItem];
		PlayerTextDrawHide(playerid,BOXINV[playerid][row]);
		PlayerTextDrawColor(playerid, BOXINV[playerid][row], 9109704);
		PlayerTextDrawShow(playerid,BOXINV[playerid][row]);
	}

	PlayerData[playerid][pSelectItem] = -1;
}