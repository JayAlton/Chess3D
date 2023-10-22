// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ChessPlayer.generated.h"

UCLASS()
class CHESS3D_API AChessPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AChessPlayer(int32 playerIndex);

	enum class EPieceColor
	{
		White,
		Black
	};

	enum class EPlayerType
	{
		Human,
		AI
	};
	
	EPlayerType PlayerType;
	EPieceColor PieceColor;

	virtual void PlayerMove(FVector startPos, FVector endPos);
	virtual void setPlayerName(FString name);
	virtual FString getPlayerName();
	virtual void setMatchesPlayed(int32 num);
	virtual int32 getMatchesPlayed();
	virtual void setWins(int32 wins);
	virtual int32 getWins();
	virtual void setLosses(int32 losses);
	virtual int32 getLosses();
	virtual void setDraws(int32 draws);
	virtual int32 getDraws();
	virtual void setLetter(FString letter);
	virtual char getLetter();
	virtual void setNumber(int32 number);
	virtual int32 getNumber();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString letter; //rows in chess are represented by letters left-right

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 number; //cols in chess are represented by numbers up-down
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 matchesPlayed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 wins;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 losses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 draws;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
