#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Piece.h" // Include the Piece class header if necessary
#include "Board.generated.h"

UCLASS()
class CHESS3D_API ABoard : public AActor
{
	GENERATED_BODY()

public:
	ABoard();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board")
	int32 BoardSizeX; // Width of the board
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board")
	int32 BoardSizeY; // Height of the board

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board")
	FVector StartPos; // Starting position of the board

	// The 2D array to represent the board
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board")
	TArray<int32> BoardGrid;

	// The array to store pieces
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board")
	TArray<APiece*> PieceSet; // Assuming APiece is your piece class

	// Function to initialize the board
	UFUNCTION(BlueprintCallable, Category = "Board")
	void InitializeBoard();

	// Function to place pieces on the board
	UFUNCTION(BlueprintCallable, Category = "Board")
	void PlacePieces();

	// Add more functions to interact with the board, such as moving pieces, checking for valid moves, etc.
};

