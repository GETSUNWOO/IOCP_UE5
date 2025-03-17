// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/S1Archer.h"
#include "S1Archer.h"
#include "S1.h"
#include <Kismet\KismetMathLibrary.h>


AS1Archer::AS1Archer()
{
}

void AS1Archer::BeginPlay()
{
	Super::BeginPlay();
}

void AS1Archer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AS1Archer::SetDesiredMove()
{
	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		//Cache
		{
			DesiredMoveDirection = FVector::ZeroVector;
			DesiredMoveDirection += ForwardDirection * DesiredInput.Y;
			DesiredMoveDirection += RightDirection * DesiredInput.X;
			DesiredMoveDirection.Normalize();

			const FVector Location = GetActorLocation();
			FRotator Rotator = UKismetMathLibrary::FindLookAtRotation(Location, Location + DesiredMoveDirection);
			DesiredYaw = Rotator.Yaw;
		}
	}
}
