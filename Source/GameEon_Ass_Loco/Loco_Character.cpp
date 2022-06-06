// Fill out your copyright notice in the Description page of Project Settings.


#include "Loco_Character.h"
#include "Components/SkeletalMeshComponent.h"

#include "GameFramework/Actor.h"

// Sets default values
ALoco_Character::ALoco_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent() -> InitCapsuleSize(42.0f, 96.0f);							//Get Capsule Component and Set its size
	
	bUseControllerRotationPitch = false;											//Disable Rotation of acapsule
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;						//Set up Rotation to Movement for direction of Character
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.f, 0.0f);				//Disable Rotation on X and Y axis
	GetCharacterMovement()->JumpZVelocity = 600.0f;									//Set Jump velocity
	GetCharacterMovement()->AirControl = 0.2f;										//Set Air Control so its hard to turn in Air

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));	//Create Camera Boom
	CameraBoom->SetupAttachment(RootComponent);										//Attach Camera Boom to Root Component

	CameraBoom->TargetArmLength = 300.0f;											//Set Camera Boom Length
	CameraBoom->bUsePawnControlRotation = true;										//Enable Camera Boom to roatate

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));	//Create FollowCamera
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent:: SocketName);	//Attach FollowCamera to Camera Boom
	FollowCamera->bUsePawnControlRotation = false;									//Disale roation on Camera

	isCrouching = false;															//Initialize Custom Properties
	IsArmed = false;																// Which Determine Animation State
	ItemWeight = 0;
	IsReloading = false;

	
}

// Called when the game starts or when spawned
void ALoco_Character::BeginPlay()
{
	Super::BeginPlay();
	
	if (Character_UI != nullptr)									//If character has Property of Character_UI
	{
		Character_Widget = CreateWidget(GetWorld(), Character_UI);	//Create Widget of Character_UI Class
		Character_Widget->AddToViewport();							//Add Widget to View port
	}

}

// Called every frame
void ALoco_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALoco_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);			//Bind Axises and Actions to Functions
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter:: Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ALoco_Character::Crouch);
	//PlayerInputComponent->BindAction("PickUp", IE_Pressed, this, &ALoco_Character::Interact);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &ALoco_Character::Reloading);

	PlayerInputComponent->BindAxis("MoveForward", this, &ALoco_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALoco_Character::MoveRight);


}


void ALoco_Character::MoveForward(float Axis)
{
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);									//Get Yaw to determine forward direction

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);		//Forward Direction of Character
	AddMovementInput(Direction, Axis);													//Movement Function
}

void ALoco_Character::MoveRight(float Axis)
{
	const FRotator Rotation = Controller->GetControlRotation();						//Get Yaw to determine Right Direction
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);	//Right direction of Character
	AddMovementInput(Direction, Axis);												//Movement Function
}

void ALoco_Character::Crouch()
{
	if (isCrouching == true)														//If Character Already Crouching make him stand else make him crouch
	{
		isCrouching = false;
		GetCharacterMovement()->JumpZVelocity = 600.0f;							//Set Jumpz velocity back to 600 after crouching is over
	}

	else
	{
		isCrouching = true;
		GetCharacterMovement()->JumpZVelocity = 450.0f;						//Reduce JumpZ velocity when crouching
	}
}

void ALoco_Character::Reloading()
{
	if (IsReloading == true)												// If weapon is being reloaded cancel it else start reloading weapon
	{
		IsReloading = false;
	}

	else
	{
		IsReloading = true;
	}
}