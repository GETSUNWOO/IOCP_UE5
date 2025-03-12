#pragma once

class ObjectUtils
{
public:
	static PlayerRef CreatePlayer(GameSessionRef session,Protocol::PlayerType playerType);

private:
	static atomic<int64> s_idGenerator;
};

