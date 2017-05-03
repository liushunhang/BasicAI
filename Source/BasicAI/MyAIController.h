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
	//行为树的引用
	class UBehaviorTreeComponent* BehaviorTreeComp;
	//黑板组件的引用
	class UBlackboardComponent* BlackboardComp;
	//黑板存储值
	FName LocationToGoKey;
	//存储AI的寻路点
	TArray<AActor*> BotTargetPoints;
	//绑定我们要控制的Character ,当这个Character生成的时候，这个函数就会被执行，我们在这里面初始化行为树 和 黑板
	virtual void Possess(APawn* InPawn) override;

#pragma endregion
public:
	
	AMyAIController();

	FORCEINLINE UBlackboardComponent *GetBlackboardComponent() { return BlackboardComp; }
	FORCEINLINE TArray<AActor*> GetAvailableTargetPoints() { return BotTargetPoints; }
	
};
