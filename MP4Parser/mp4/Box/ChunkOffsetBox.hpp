//
//  ChunkOffsetBox.hpp
//  MP4Parser
//
//  Created by dKingbin on 2018/9/20.
//  Copyright © 2018年 dKingbin. All rights reserved.
//

#ifndef ChunkOffsetBox_hpp
#define ChunkOffsetBox_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

#include "PtrBuffer.hpp"
#include "Box.hpp"
#include "FullBox.hpp"

namespace ffstl
{
	//stco
	class ChunkOffsetBox : public FullBox
	{
	public:
		ChunkOffsetBox(std::shared_ptr<PtrBuffer> buffer) : FullBox(buffer)
		{}

		virtual void parser(size_t& size)
		{
			FullBox::parser(size);

			entry_count_ = buffer_->readBig32();
			for(int i=0;i<entry_count_;i++)
			{
				int val = buffer_->readBig32();
				entries_.push_back(val);
			}
		}

	protected:
		uint32_t entry_count_;
		std::vector<int> entries_;
	};
}

#endif /* ChunkOffsetBox_hpp */
