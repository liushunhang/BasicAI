// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicAI.h"
#include "BotTargetPoint.h"
#include "MyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTTargetPointSelection.h"

EBTNodeResult::Type UBTTargetPointSelection::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//得到当前AI控制器
	AMyAIController* AICon = Cast<AMyAIController>(OwnerComp.GetAIOwner());

	if (AICon)
	{
		//得到黑板组件
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();

		//得到当前目标点
		ABotTargetPoint* CurrentPoint = Cast<ABotTargetPoint>(BlackboardComp->GetValueAsObject("LocationToGo"));

		//得到所有有效目标点
		TArray<AActor*> AvailableTargetPoints = AICon->GetAvailableTargetPoints();

		//随机索引
		int RandomIndex;

		//下个目标点
		ABotTargetPoint *NextTargetPoint = nullptr;

		//根据索引找到下一个可能的目标点 -与当前目标点不一样的点
		do
		{
			RandomIndex = FMath::RandRange(0, AvailableTargetPoints.Num() - 1);
			NextTargetPoint = Cast<ABotTargetPoint>(AvailableTargetPoints[RandomIndex]);
		} while (CurrentPoint==NextTargetPoint);

		//找到一个点后  更新
		BlackboardComp->SetValueAsObject("LocationToGo", NextTargetPoint);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
