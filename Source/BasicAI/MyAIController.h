// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class BASICAI_API AMyAIController : public AAIController
{
	GENERATED_BODY()
#pragma region AI
private:
	//��Ϊ��������
	class UBehaviorTreeComponent* BehaviorTreeComp;
	//�ڰ����������
	class UBlackboardComponent* BlackboardComp;
	//�ڰ�洢ֵ
	FName LocationToGoKey;
	//�洢AI��Ѱ·��
	TArray<AActor*> BotTargetPoints;
	//������Ҫ���Ƶ�Character ,�����Character���ɵ�ʱ����������ͻᱻִ�У��������������ʼ����Ϊ�� �� �ڰ�
	virtual void Possess(APawn* InPawn) override;

#pragma endregion
public:
	
	AMyAIController();

	FORCEINLINE UBlackboardComponent *GetBlackboardComponent() { return BlackboardComp; }
	FORCEINLINE TArray<AActor*> GetAvailableTargetPoints() { return BotTargetPoints; }
	
};
