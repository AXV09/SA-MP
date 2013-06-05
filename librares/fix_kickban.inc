/**
 *			FIX_KickBan
 *					By AXV09
 */

#if defined fix_kickban_inc
	#endinput
#else
	#define fix_kickban_inc
#endif

#define Kick(%1)	FIX_Kick(%1)
#define Ban(%1)		FIX_Ban(%1)
#define BanEx(%1)	FIX_BanEx(%1)

#include <a_samp>

native fixedKick(playerid) = Kick;
native fixedBan(playerid) = Ban;
native fixedBanEx(playerid, const reason[]) = BanEx(playerid, reason);


// functions
stock FIX_Kick(playerid)
{
	SetTimerEx(!"fixtimer_Kick", 1, false, !"d", playerid);
}

stock FIX_Ban(playerid)
{
	SetTimerEx(!"fixtimer_Ban", 1, false, !"d", playerid);
}

stock FIX_BanEx(playerid, const reason[])
{
	SetTimerEx(!"fixtimer_BanEx", 1, false, !"ds", playerid, reason);
}

// calls timers
forward fixtimer_Kick(playerid);
public fixtimer_Kick(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		fixedKick(playerid);
		return 1;
	}
	return 0;
}

forward fixtimer_Ban(playerid);
public fixtimer_Ban(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		fixedBan(playerid);
		return 1;
	}
	return 0;
}

forward fixtimer_BanEx(playerid, reason[]);
public fixtimer_BanEx(playerid, reason[])
{
	if(IsPlayerConnected(playerid))
	{
		fixedBanEx(playerid, reason);
		return 1;
	}
	return 0;
}
// eof