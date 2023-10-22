// Fill out your copyright notice in the Description page of Project Settings.


#include "Piece.h"

// Sets default values
APiece::APiece()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APiece::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APiece::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
// Implement the isValidMove function
bool APiece::isValidMove(FVector Target)
{
	// Add your implementation to check if the move is valid
	return true; // Replace with your actual implementation
}

// Implement the move function
void APiece::move(FVector Target)
{
	// Add your implementation to move the piece to the target position
}

// Implement getCurrentPos function
FVector APiece::getCurrentPos()
{
	return CurrentPos;
}

// Implement setCurrentPos function
void APiece::setCurrentPos(FVector NewPos)
{
	CurrentPos = NewPos;
}

// Implement getValidMoves function
TArray<FVector> APiece::getValidMoves()
{
	return validMoves;
}

// Implement setValidMoves function
void APiece::setValidMoves(TArray<FVector> NewValidMoves)
{
	validMoves = NewValidMoves;
}
