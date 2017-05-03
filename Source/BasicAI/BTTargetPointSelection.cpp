// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicAI.h"
#include "BotTargetPoint.h"
#include "MyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTTargetPointSelection.h"

EBTNodeResult::Type UBTTargetPointSelection::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//�õ���ǰAI������
	AMyAIController* AICon = Cast<AMyAIController>(OwnerComp.GetAIOwner());

	if (AICon)
	{
		//�õ��ڰ����
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();

		//�õ���ǰĿ���
		ABotTargetPoint* CurrentPoint = Cast<ABotTargetPoint>(BlackboardComp->GetValueAsObject("LocationToGo"));

		//�õ�������ЧĿ���
		TArray<AActor*> AvailableTargetPoints = AICon->GetAvailableTargetPoints();

		//�������
		int RandomIndex;

		//�¸�Ŀ���
		ABotTargetPoint *NextTargetPoint = nullptr;

		//���������ҵ���һ�����ܵ�Ŀ��� -�뵱ǰĿ��㲻һ���ĵ�
		do
		{
			RandomIndex = FMath::RandRange(0, AvailableTargetPoints.Num() - 1);
			NextTargetPoint = Cast<ABotTargetPoint>(AvailableTargetPoints[RandomIndex]);
		} while (CurrentPoint==NextTargetPoint);

		//�ҵ�һ�����  ����
		BlackboardComp->SetValueAsObject("LocationToGo", NextTargetPoint);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
