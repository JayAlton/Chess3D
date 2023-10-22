// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessPlayer.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AChessPlayer::AChessPlayer(int32 playerIndex)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), playerIndex); // 0 for the first player
	ACharacter* player = Cast<ACharacter>(PlayerController->GetPawn());
	if(player)
	{
		FVector CurrentLocation = player->GetActorLocation();
		UE_LOG(LogTemp, Warning, TEXT("Character Location: %s"), *CurrentLocation.ToString());

		//Implement current location into letter and number such as A1-H8
		//hint: Board class
	}
}

// Called when the game starts or when spawned
void AChessPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChessPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AChessPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

