#include "BullsAndCows.h"

FString UBullsAndCows::GenerateRandomNumber()
{
	TArray<int32> Numbers;
	for (int32 i = 1; i <= 9; i++)
	{
		Numbers.Add(i);
	}

	FString Result;
	for (int32 i = 0; i < 3; i++) 
	{
		int32 Index = FMath::RandRange(0, Numbers.Num() - 1);
		Result.Append(FString::FromInt(Numbers[Index]));
		Numbers.RemoveAt(Index); // 중복 방지
	}

	return Result;
}

FString UBullsAndCows::CheckBullsAndCows(const FString& ServerNumber, const FString& PlayerNumber)
{
	int32 Strikes = 0;
	int32 Balls = 0;

	for (int32 i = 0; i < 3; i++)
	{
		if (ServerNumber[i] == PlayerNumber[i]) // 자리와 값이 같으면 S 증가
		{
			Strikes++;
		}
		else if (ServerNumber.Contains(FString::Chr(PlayerNumber[i]))) // 값만 포함되면 B 증가
		{
			Balls++;
		}
	}
    
	return FString::Printf(TEXT("%dS%dB"), Strikes, Balls);
}

bool UBullsAndCows::ValidatePlayerNumber(const FString& PlayerNumber)
{
	// 3자리 숫자인지 체크
	if (PlayerNumber.Len() != 3)
	{
		return false;
	}

	// 중복된 숫자 있는지 체크 
	TSet<TCHAR> UniqueNumbers;
	for (TCHAR Char : PlayerNumber)
	{
		if (UniqueNumbers.Contains(Char))
		{
			return false; 
		}
		UniqueNumbers.Add(Char);
	}

	return true;
}
