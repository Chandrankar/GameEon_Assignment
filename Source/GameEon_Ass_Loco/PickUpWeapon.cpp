// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpWeapon.h"

// Sets default values
APickUpWeapon::APickUpWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	active = true;
}

// Called when the game starts or when spawned
void APickUpWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickUpWeapon::Interacted()
{
	active = false;
	SetActorHiddenInGame(true);

}

bool APickUpWeapon::GetActive()
{
	return active;
}