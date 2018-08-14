// Fill out your copyright notice in the Description page of Project Settings.

#include "MassComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "BalanceMass.h"

// Sets default values for this component's properties
UMassComponent::UMassComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UMassComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*>  balanceActorsFounded;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABalanceMass::StaticClass(), balanceActorsFounded);

	if (balanceActorsFounded.Num() > 0)
	{
		balanceActor = Cast<ABalanceMass>(balanceActorsFounded[0]);
	}
	
	GetBalanceValues();

}

void UMassComponent::GetBalanceValues()
{
	// If exist a valid Big Minimap
	if (IsValid(balanceActor))
	{
		
		switch (MassType)
		{
		default:
		case EMassType::NONE:
		case EMassType::EChair:
			Mass = balanceActor->GetMassChair();
			break;
		case EMassType::ETable:
			Mass = balanceActor->GetMassTable();
			break;
			break;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("balance Actor Doesn't found"));
	}
}

// Called every frame
void UMassComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}