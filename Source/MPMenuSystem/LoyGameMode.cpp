// Fill out your copyright notice in the Description page of Project Settings.


#include "LoyGameMode.h"

#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

void ALoyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if(GameState)
	{
		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Yellow, FString::Printf(TEXT("Players in game: %d"), NumberOfPlayers));
			if(APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>())
			{
				FString PlayerName = PlayerState->GetPlayerName();
				GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Cyan, FString::Printf(TEXT("%s has joined the game."), *PlayerName));
			}
		}
	}
}

void ALoyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	if(GameState)
	{
		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Yellow, FString::Printf(TEXT("Players in game: %d"), NumberOfPlayers - 1));
			if(APlayerState* PlayerState = Exiting->GetPlayerState<APlayerState>())
			{
				FString PlayerName = PlayerState->GetPlayerName();
				GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Cyan, FString::Printf(TEXT("%s has exited the game."), *PlayerName));
			}
		}
	}
}
