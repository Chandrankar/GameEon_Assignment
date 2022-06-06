// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/inputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "Blueprint/UserWidget.h"

#include "Loco_Character.generated.h"

UCLASS()
class GAMEEON_ASS_LOCO_API ALoco_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALoco_Character();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)		//Camera Boom to attach Camera
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)		//Follow Camera of the charracter
		UCameraComponent* FollowCamera;

	void MoveForward(float Axis);											//Move forward Function
	void MoveRight(float Axis);												//Move Right Function

	void Crouch();															//Crouch Function

	UPROPERTY(EditAnywhere, BlueprintReadWrite)								//Property to determine if character is Crouching
		bool isCrouching;
				

	UPROPERTY(EditAnywhere, BlueprintReadWrite)								//Property to determine if Character has weapons
		bool IsArmed;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)								//Property to determine what weapon is Character holding
		int ItemWeight;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)								//Property to determine if Character is reloading weapons or Not
		bool IsReloading;

	void Reloading();

	UPROPERTY(EditAnywhere, Category = "UI HUD")							//Add UI Hud for Instructions
		TSubclassOf<UUserWidget> Character_UI;
	UUserWidget* Character_Widget;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
