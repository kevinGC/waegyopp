#include "Landlock.h"
#include <memory>
using std::shared_ptr; using std::static_pointer_cast;


bool Landlock::can_be_occupied_by(shared_ptr<const Piece>& piece) const
{
	auto self = static_pointer_cast<const Landlock>(shared_from_this());
	return piece->can_occupy(self);
}
