// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "BTTargetPointSelection.generated.h"

/**
 * 
 */
UCLASS()
class BASICAI_API UBTTargetPointSelection : public UBTTaskNode
{
	GENERATED_BODY()
public:
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
	
};
