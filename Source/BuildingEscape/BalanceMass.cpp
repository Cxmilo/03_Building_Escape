// Fill out your copyright notice in the Description page of Project Settings.

#include "BalanceMass.h"


// Sets default values
ABalanceMass::ABalanceMass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABalanceMass::BeginPlay()
{
	Super::BeginPlay();
	ReadDataTable();
	
}

void ABalanceMass::ReadDataTable()
{
	if (IsValid(massDataTable))
	{
		FMassBalanceStruct*  data = massDataTable->FindRow<FMassBalanceStruct>(presetName, "", false);
		SetMassTable(data->MassTable);
		SetMassChair(data->MassChair);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Data Table is invalid"));
	}
}

// Called every frame
void ABalanceMass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABalanceMass::SetMassTable(float MassTable)
{
	this->MassTable = MassTable;
}

void ABalanceMass::SetMassChair(float MassChair)
{
	this->MassChair = MassChair;
}

float ABalanceMass::GetMassTable()
{
	ReadDataTable();
	return this->MassTable;
}

float ABalanceMass::GetMassChair()
{
	ReadDataTable();
	return this->MassChair;
}

