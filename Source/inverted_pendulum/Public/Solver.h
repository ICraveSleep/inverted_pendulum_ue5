// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"

/**
 * 
 */
class INVERTED_PENDULUM_API FSolver : public FRunnable
{
public:
	explicit FSolver(UWorld* UWorldPtr);
	virtual ~FSolver() override;

	// FRunnable Pure Virtual functions
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;

	bool IsRunning() const {return !bStopThread;}
	void GetPose(float& Position, float& Rotation);

protected:
	FCriticalSection UE4_Mutex;
	FRunnableThread* Thread = nullptr;

	UWorld* WorldPtr;
	bool bStopThread;
	float CartPosition;
	float PoleRotation;
	
};