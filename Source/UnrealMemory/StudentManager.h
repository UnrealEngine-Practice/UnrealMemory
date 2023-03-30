// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Student.h"
/**
 * 
 */
class UNREALMEMORY_API FStudentManager : public FGCObject
{
public:
	FStudentManager(class UStudent* InStudent)
		: SafeStudent(InStudent) {};
	const class UStudent* GetStudent() const {return SafeStudent;}

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override
	{
		if (SafeStudent->IsValidLowLevel() == true)
		{
			// 등록하는 부분
			Collector.AddReferencedObject(SafeStudent);
			
		}
	}

	virtual FString GetReferencerName() const override
	{
		// 고유한 클래스 이름을 반환해주면 된다.
		return TEXT("FStudentManager");
	}
private:
	class UStudent* SafeStudent = nullptr;
};
