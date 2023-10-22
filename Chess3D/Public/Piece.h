// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Piece.generated.h"

UCLASS(Abstract)
class CHESS3D_API APiece : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APiece();
	virtual FVector getCurrentPos();
	virtual void setCurrentPos(FVector newPos);
	virtual TArray<FVector> getValidMoves();
	virtual void setValidMoves(TArray<FVector> newValidMoves);
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
	
	virtual bool isValidMove(FVector target);
	virtual void move(FVector target);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
