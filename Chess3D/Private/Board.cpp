#include "Board.h"

ABoard::ABoard()
{
	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;
}

void ABoard::InitializeBoard()
{
	// Resize the board grid to the specified dimensions and initialize values
	int32 TotalCells = BoardSizeX * BoardSizeY;
	BoardGrid.Init(0, TotalCells);
}

void ABoard::PlacePieces()
{
	//Place Black and White Pieces
	for(int32 i = 0 ; i < BoardSizeX ; i++)
	{
		AActor* NewPiece = GetWorld()->SpawnActor(StaticClass<APiece>());
		APiece* MyPiece = Cast<APiece>(NewPiece);
		
		if(NewPiece)
		{
			//MyPiece->SetOwner(Player1);
			MyPiece->setCurrentPos(FVector(i, BoardSizeY - 1, 0));
			PieceSet.Add(MyPiece);
		}
	}
}

// Implement other functions to interact with the board as needed
