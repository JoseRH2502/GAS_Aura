// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AbilityInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct  FAuraAbilityInfo
{
	GENERATED_BODY()
	
	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag AbilityTag;

	UPROPERTY (BlueprintReadOnly)
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag CooldownTag = FGameplayTag();

	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<const UTexture2D> AttributeIcon = nullptr;

	UPROPERTY (EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<const UMaterialInterface> BackgroundMaterial = nullptr;
};
UCLASS()
class AURA_API UAbilityInfo : public UDataAsset
{
	GENERATED_BODY()

public:
 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AbilityInformation")
	TArray<FAuraAbilityInfo> AbilityInformation;
 
	FAuraAbilityInfo FindAbilityInfoForTag(const FGameplayTag& AbilityTag, bool bLogNotFound = false) const;
};
