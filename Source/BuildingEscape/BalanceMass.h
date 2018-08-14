// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "BalanceMass.generated.h"

USTRUCT(BlueprintType)
struct  FMassBalanceStruct: public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(BlueprintReadWrite)
		float MassChair;
	UPROPERTY(BlueprintReadWrite)
		 float MassTable;
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGetBalanceRequest);
UCLASS()
class BUILDINGESCAPE_API ABalanceMass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABalanceMass();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BalanceVar)
		float MassTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BalanceVar)
		float MassChair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BalanceVar)
		FName presetName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BalanceVar)
	UDataTable* massDataTable;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ReadDataTable();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetMassTable(float MassTable);
	void SetMassChair(float MassChair);

	float GetMassTable();
	float GetMassChair();

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite)
		FGetBalanceRequest OnDataLoaded;
	
};
