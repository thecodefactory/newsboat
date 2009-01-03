/* rsspp - Copyright (C) 2008-2009 Andreas Krennmair <ak@newsbeuter.org>
 * Licensed under the MIT/X Consortium License. See file LICENSE
 * for more information.
 */

#include <config.h>
#include <rsspp_internal.h>

namespace rsspp {

std::tr1::shared_ptr<rss_parser> rss_parser_factory::get_object(feed& f) {
	switch (f.rss_version) {
		case RSS_0_91:
		case RSS_0_92:
			return std::tr1::shared_ptr<rss_parser>(new rss_09x_parser());
		case RSS_2_0:
			return std::tr1::shared_ptr<rss_parser>(new rss_20_parser());
		case RSS_1_0:
			return std::tr1::shared_ptr<rss_parser>(new rss_10_parser());
		case ATOM_0_3:
		case ATOM_1_0:
			return std::tr1::shared_ptr<rss_parser>(new atom_parser());
		case UNKNOWN:
		default:
			throw exception(_("unsupported feed format"));
	}
}

}
