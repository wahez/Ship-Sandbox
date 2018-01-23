/***************************************************************************************
* Original Author:		Gabriele Giuseppini
* Created:				2018-01-19
* Copyright:			Gabriele Giuseppini  (https://github.com/GabrieleGiuseppini)
***************************************************************************************/
#pragma once

/*
* Parameters that affect the game (physics, world).
*/
struct GameParameters
{
	float Strength;
	float Buoyancy;
	float WaveHeight;
	float WaterPressure;
	float SeaDepth;

	// TODO - here or render?
	bool QuickWaterFix;

	GameParameters()
		: Strength(0.01f)
		, Buoyancy(4.0f)
		, WaveHeight(1.0f)
		, WaterPressure(0.3f)
		, SeaDepth(150.0f)
		, QuickWaterFix(false)
	{
	}
};
