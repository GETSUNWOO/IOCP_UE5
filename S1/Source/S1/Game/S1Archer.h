// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Game/S1MyPlayer.h"
#include "S1Archer.generated.h"

/**
 * 
 */
UCLASS()
class S1_API AS1Archer : public AS1MyPlayer
{
	GENERATED_BODY()
public:
	AS1Archer();

protected:
	virtual void BeginPlay()override;
	virtual void Tick(float DeltaTime)override;

public:
	UFUNCTION(BlueprintCallable)
	void SetDesiredMove();

	UFUNCTION(BlueprintCallable)
	void SetDesiredInputX(double value) { DesiredInput.X = value; }
	UFUNCTION(BlueprintCallable)
	void SetDesiredInputY(double value) { DesiredInput.Y = value; }
};
