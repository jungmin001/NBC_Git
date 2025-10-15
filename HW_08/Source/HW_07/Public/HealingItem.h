#pragma once

#include "CoreMinimal.h"
#include "CoinItem.h"
#include "HealingItem.generated.h"

UCLASS()
class HW_07_API AHealingItem : public ABaseItem
{
	GENERATED_BODY()

public:
	AHealingItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 HealAmount;

	virtual void ActivateItem(AActor* Activator) override;

};
