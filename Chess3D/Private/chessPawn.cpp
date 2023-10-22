// Fill out your copyright notice in the Description page of Project Settings.


#include "chessPawn.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AchessPawn::AchessPawn(int32 playerIndex)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), playerIndex); // 0 for the first player
	AchessPawn* player = Cast<AchessPawn>(PlayerController->GetPawn());
	if(player)
	{
		FVector CurrentLocation = player->GetActorLocation();
		UE_LOG(LogTemp, Warning, TEXT("Character Location: %s"), *CurrentLocation.ToString());

		Forward1 = CurrentLocation + GetActorForwardVector() * 8.5f;
		Forward2 = CurrentLocation + GetActorForwardVector() * 17.0f;
		ForwardLeft = CurrentLocation +
						(GetActorForwardVector() * 8.5f) +
						(-GetActorRightVector() * 8.5f);
		ForwardRight = CurrentLocation +
						(GetActorForwardVector() * 8.5f) +
						(GetActorRightVector() * 8.5f);

		CurrentPos = CurrentLocation;

		TArray<FVector> NewValidMoves;
		NewValidMoves.Add(Forward1);
		NewValidMoves.Add(Forward2);
		validMoves = NewValidMoves;
	}
	
}


// Called when the game starts or when spawned
void AchessPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AchessPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AchessPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AchessPawn::setCurrentPos(FVector newPos)
{
	CurrentPos =  newPos;

	Forward1 = CurrentPos + GetActorForwardVector() * 8.5f;
	Forward2 = CurrentPos + GetActorForwardVector() * 17.0f;
	ForwardLeft = CurrentPos +
					(GetActorForwardVector() * 8.5f) +
					(-GetActorRightVector() * 8.5f);
	ForwardRight = CurrentPos +
					(GetActorForwardVector() * 8.5f) +
					(GetActorRightVector() * 8.5f);

	TArray<FVector> NewValidMoves;
	NewValidMoves.Add(Forward1);
	NewValidMoves.Add(Forward2);

	//add Forward left or right if enemy piece is in square or enPASSANT
	
	validMoves = NewValidMoves;
	
}

void AchessPawn::setValidMoves(TArray<FVector> newValidMoves)
{
	validMoves = newValidMoves;
}


bool AchessPawn::isValidMove(FVector target) 
{
	for(int i = 0 ; i < validMoves.Num() ; i++)
	{
		if(target == validMoves[i])
		{
			return true;		
		}
	}
	return false;
}
