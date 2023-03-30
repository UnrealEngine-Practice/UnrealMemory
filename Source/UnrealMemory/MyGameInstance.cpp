// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"

void CheckUObjectIsValid(const UObject* InObject, const FString& InTag)
{
	if (InObject->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Log, TEXT("[%s]유효한 오브젝트"), *InTag);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[%s]유효하지 않은 오브젝트"), *InTag);
	}
	
}

void CheckUObjectIsNull(const UObject* InObject, const FString& InTag)
{
	if (nullptr == InObject)
	{
		UE_LOG(LogTemp, Log, TEXT("[%s]Null 오브젝트"), *InTag);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[%s]Non Null 오브젝트"), *InTag);
	}
	
}

void UMyGameInstance::Init()
{
	Super::Init();

	NonUPropertyObj = NewObject<UStudent>();
	UPropertyObj = NewObject<UStudent>();
}

void UMyGameInstance::Shutdown()
{
	Super::Shutdown();
	
	CheckUObjectIsNull(NonUPropertyObj, TEXT("NonUPropertyObj"));
	CheckUObjectIsNull(UPropertyObj, TEXT("UPropertyObj"));
	CheckUObjectIsValid(NonUPropertyObj, TEXT("NonUPropertyObj"));
	CheckUObjectIsValid(UPropertyObj, TEXT("UPropertyObj"));
}
