// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Piece.h"
#include "GameFramework/Pawn.h"
#include "chessPawn.generated.h"

UCLASS()
class CHESS3D_API AchessPawn : public APiece
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AchessPawn(int32 playerIndex);

	virtual FVector getCurrentPos();
	virtual void setCurrentPos(FVector newPos);
	virtual TArray<FVector> getValidMoves();
	virtual void setValidMoves(TArray<FVector> newValidMoves);
	virtual bool isValidMove(FVector target); __override
	virtual void move(FVector target); __override
	//virtual Player getPieceOwner();
	//virtual void setPieceOwner(Player owner);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Pawn")
	FVector CurrentPos; // Variable to store the current position of the piece

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FVector> validMoves;
	//Player pieceOwner;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector Forward1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector Forward2;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector ForwardLeft;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector ForwardRight;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
