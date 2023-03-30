// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UNREALMEMORY_API FStudentManager
{
public:
	FStudentManager(class UStudent* InStudent)
		: SafeStudent(InStudent) {};
	const class UStudent* GetStudent() const {return SafeStudent;}
private:
	class UStudent* SafeStudent = nullptr;
};
