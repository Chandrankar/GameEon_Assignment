// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"

#include "PickUpWeapon.generated.h"

UCLASS()
class GAMEEON_ASS_LOCO_API APickUpWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int weaponWeight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Interacted();
	bool GetActive();

	//UPROPERTY(EditAnywhere, Category = "Mesh")
	//	class UStaticMeshComponent* mesh;


private:
	UPROPERTY()
		bool active;

	
};
