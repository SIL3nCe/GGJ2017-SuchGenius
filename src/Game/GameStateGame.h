#pragma once

#include "State.h"

class GameStateGame : public State
{

public:

	explicit	GameStateGame		(void);
	virtual		~GameStateGame		(void);

	void		init				(void) SH_ATTRIBUTE_OVERRIDE;
	void		release				(void) SH_ATTRIBUTE_OVERRIDE;

	void		entered				(void) SH_ATTRIBUTE_OVERRIDE;
	void		exiting				(void) SH_ATTRIBUTE_OVERRIDE;

	void		obscuring			(void) SH_ATTRIBUTE_OVERRIDE;
	void		revealed			(void) SH_ATTRIBUTE_OVERRIDE;

	void		update				(float dt) SH_ATTRIBUTE_OVERRIDE;

	void		touchBegin			(const CShVector2 & pos) SH_ATTRIBUTE_OVERRIDE;
	void		touchEnd			(const CShVector2 & pos) SH_ATTRIBUTE_OVERRIDE;
	void		touchMove			(const CShVector2 & pos) SH_ATTRIBUTE_OVERRIDE;

protected:

	void		load				(void);
	void		unload				(void);

	ShEntity2 * m_pPressedButton;
	ShEntity2 * m_pRestartButton;
	ShEntity2 * m_pHomeButton;

};
