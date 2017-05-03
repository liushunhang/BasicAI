// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicAI.h"
#include "MyAIController.h"
#include "AICharacter.h"
#include "BotTargetPoint.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AMyAIController::AMyAIController()
{
	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(FName("BehaviorTreeComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(FName("BlackboardComp"));
	LocationToGoKey = "LocationToGo";
}
void AMyAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
	AAICharacter* AICha = Cast<AAICharacter>(InPawn);
	if (AICha)
	{
		if (AICha->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(AICha->BehaviorTree->BlackboardAsset));
		}
	}

	//��ȡѰ·����Ч��
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), BotTargetPoints);
	//������Ϊ��
	BehaviorTreeComp->StartTree(*AICha->BehaviorTree);
}