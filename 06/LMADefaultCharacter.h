protected:
/**Sprint**/
UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Movement")
bool SprintEnabled = false;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
float Stamina = 20.0f; 
private:
	void StartSprint();
	void StopSprint();
	void ActionWithStamina(float DeltaTime);
