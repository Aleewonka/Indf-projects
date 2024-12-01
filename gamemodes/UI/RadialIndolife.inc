#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_NO)
	{
		if(playerid != INVALID_PLAYER_ID)
		{
			if(pData[playerid][pInjured] == 1)
			return Error(playerid, "Kamu sedang down.");

			ShowPanelS(playerid); //Radial
			SelectTextDraw(playerid, 0x878787FF);
		}
	}
	return 1;
}
