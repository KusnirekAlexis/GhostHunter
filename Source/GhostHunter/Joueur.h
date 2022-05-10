// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Flashlight.h"
#include "Joueur.generated.h"

UCLASS()
class GHOSTHUNTER_API AJoueur : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AJoueur();
	void MoveForward(float Axis);
	void MoveRight(float Axis);
	void LookUp(float Rate);
	void LookRight(float Rate);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Lampe)
		TSubclassOf<class AFlashlight> Light;

};
