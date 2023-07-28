void ALMADefaultCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!(HealthComponent->IsDead()))
	{
		ActionWithStamina(DeltaTime);
	}
}

void ALMADefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ALMADefaultCharacter::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ALMADefaultCharacter::StopSprint);
}

void ALMADefaultCharacter::StartSprint()
{
	SprintEnabled = true;
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
}

void ALMADefaultCharacter::StopSprint()
{
	SprintEnabled = false;
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
}

void ALMADefaultCharacter::ActionWithStamina(float DeltaTime)
{
	if (SprintEnabled)
	{
		if (Stamina > 0.0f)
		{
			Stamina -= 0.1f;
		}
		else if (Stamina <= 0.0f)
		{
			StopSprint();
		}
	}
	else if (!SprintEnabled && Stamina < 10.0f)
	{
		Stamina += 0.1f;
	}
} 
