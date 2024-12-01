static const Float:CordCircle[][3] =
{
	{2722.749023,-2208.330810, 100.0},
	{2522.014160,-2111.694091,1030.446899}
};
new CircleArea[sizeof(CordCircle)];

stock UpdateChunkSize()
{
    new playerCount = GetPlayerPoolSize();
    if (playerCount > 20){
    Streamer_SetChunkSize(STREAMER_TYPE_OBJECT, 25);}
    else{
    Streamer_SetChunkSize(STREAMER_TYPE_OBJECT, 50);}
}

stock StreamerPcSettings()
{
	UpdateChunkSize();
	Streamer_SetCellDistance(300.0);
	Streamer_SetCellSize(300.0);
	Streamer_SetMaxItems(STREAMER_TYPE_OBJECT, 900);
	Streamer_SetMaxItems(STREAMER_TYPE_PICKUP, 500);
	Streamer_SetMaxItems(STREAMER_TYPE_CP, 200);
	for(new i=0; i<sizeof(CordCircle); i++){
	CircleArea[i] = CreateDynamicCircle(CordCircle[i][0], CordCircle[i][1], 150.0);}
	Streamer_SetTickRate(50);
	Streamer_ToggleErrorCallback(0);
	Streamer_AmxUnloadDestroyItems(true);
}

stock StreamerMobileSettings(playerid)
{
	Streamer_SetCellDistance(250.0);
	Streamer_SetCellSize(250.0);
	Streamer_SetMaxItems(STREAMER_TYPE_OBJECT, 500);
	Streamer_SetMaxItems(STREAMER_TYPE_PICKUP, 200);
	Streamer_SetMaxItems(STREAMER_TYPE_CP, 100);
	Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT, 300, playerid);
	Streamer_SetVisibleItems(STREAMER_TYPE_PICKUP, 100, playerid);
	Streamer_SetVisibleItems(STREAMER_TYPE_CP, 50, playerid);
	Streamer_SetRadiusMultiplier(STREAMER_TYPE_OBJECT, 1.5, playerid);
	Streamer_SetRadiusMultiplier(STREAMER_TYPE_PICKUP, 1.2, playerid);
	Streamer_SetTickRate(50);
	Streamer_ToggleErrorCallback(0);
	Streamer_AmxUnloadDestroyItems(true);
}