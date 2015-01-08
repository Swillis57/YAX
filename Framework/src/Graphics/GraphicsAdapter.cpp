#include "../../include/Graphics/DepthFormat.h"
#include "../../include/Graphics/GraphicsAdapter.h"
#include "../../include/Graphics/GraphicsProfile.h"
#include "../../include/Graphics/SurfaceFormat.h"
#include "../../include/Geometry/Rectangle.h"
#include "../../include/GLEW/glew.h"

#define glGetActualString(enum) (std::string{reinterpret_cast<const char*>(glGetString(enum))} + "\0")

namespace YAX
{
	struct GraphicsAdapter::Impl
	{
		DisplayModeCollection _supportedModes;
		std::string _name, _desc, _vendor;
		i32 _deviceID, _revision, _subSysID;
		GLFWmonitor* _handle;

		Impl(std::string desc, std::string vend, GLFWmonitor* hnd)
			: _desc(desc), _vendor(vend), _handle(hnd)
		{
			i32 modeCount;
			auto modes = glfwGetVideoModes(hnd, &modeCount);
			size_t fixedModeCount = static_cast<size_t>(modeCount);

			for (size_t j = 0; j < fixedModeCount; j++)
			{
				auto vMode = modes[j];

				_supportedModes.emplace_back(DisplayMode(
				{ vMode.redBits, vMode.blueBits, vMode.greenBits },
				Rectangle(0, 0, vMode.width, vMode.height)
				));
			}
		}
		
		~Impl() = default;

		

		bool IsProfileSupported(GraphicsProfile profile)
		{
			GLint majV;
			glGetIntegerv(GL_MAJOR_VERSION, &majV);

			//Core profile is always available, 
			//Compat is available for versions >= 3.0
			return (profile == GraphicsProfile::HiDef || majV >= 3);
		}

		DisplayMode CurrentDisplayMode() const
		{
			//Don't need to delete this, GLFW handles everything itself
			auto vMode = glfwGetVideoMode(_handle);
			return DisplayMode(
				{vMode->redBits, vMode->blueBits, vMode->greenBits},
				Rectangle(0, 0, vMode->width, vMode->height)
			);
		}

		bool IsDefault() const
		{
			return _handle == glfwGetPrimaryMonitor();
		}

		bool IsWideScreen() const
		{
			float aspRat = CurrentDisplayMode().AspectRatio();
			return aspRat == 1.77f || aspRat == 1.6;
		}
	};

	GraphicsAdapter* GraphicsAdapter::_defaultAdapter;
	std::vector<GraphicsAdapter> GraphicsAdapter::_adapters;

	GraphicsAdapter::GraphicsAdapter(std::string desc, std::string vend, GLFWmonitor* hnd)
	{
		_impl = std::make_unique<Impl>(desc, vend, hnd);
	}

	GraphicsAdapter::~GraphicsAdapter() = default;

	GraphicsAdapter::GraphicsAdapter(GraphicsAdapter&& old)
	{
		_impl = std::move(old._impl);
	}

	GraphicsAdapter::GraphicsAdapter(const GraphicsAdapter& old)
	{
		_impl = std::make_unique<Impl>(*old._impl);
	}

	GraphicsAdapter& GraphicsAdapter::operator=(const GraphicsAdapter& old)
	{
		this->_impl = std::make_unique<Impl>(*old._impl);
		return *this;
	}

	GraphicsAdapter& GraphicsAdapter::operator=(GraphicsAdapter&& old)
	{
		this->_impl = std::move(old._impl);
		return *this;
	}

	const std::vector<GraphicsAdapter>& GraphicsAdapter::Adapters()
	{
		return _adapters;
	}

	GraphicsAdapter* GraphicsAdapter::DefaultAdapter()
	{
		return _defaultAdapter;
	}

	void GraphicsAdapter::FindAdapters()
	{
		GLFWmonitor* defaultMonitor = glfwGetPrimaryMonitor();
		i32 monitorCount;
		GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);
		size_t fixedMonitorCount = static_cast<size_t>(monitorCount);

		for (size_t i = 0; i < fixedMonitorCount; i++)
		{
			std::string desc = glGetActualString(GL_RENDERER);
			std::string vend = glGetActualString(GL_VENDOR);
			
			
			_adapters.emplace_back(GraphicsAdapter { desc, vend, monitors[i] });

			if (monitors[i] == defaultMonitor)
				_defaultAdapter = &_adapters[_adapters.size() - 1];
		}
	}

	std::string GraphicsAdapter::Description() const
	{
		return _impl->_desc;
	}

	std::string GraphicsAdapter::DeviceName() const
	{
		return _impl->_name;
	}

	bool GraphicsAdapter::IsDefaultAdapter() const
	{
		return _impl->IsDefault();
	}

	bool GraphicsAdapter::IsWideScreen() const
	{
		return _impl->IsWideScreen();
	}

	GLFWmonitor* GraphicsAdapter::MonitorHandle() const
	{
		return _impl->_handle;
	}

	bool GraphicsAdapter::IsProfileSupported(GraphicsProfile profile) const
	{
		return _impl->IsProfileSupported(profile);
	}

	DisplayMode GraphicsAdapter::CurrentDisplayMode() const
	{
		return _impl->CurrentDisplayMode();
	}

	const DisplayModeCollection& GraphicsAdapter::SupportedDisplayModes() const
	{
		return _impl->_supportedModes;
	}
}