import json
import mqtt_comm as mc

class CommandTypes(object):
	COMM_ENABLE = "enabled"
	COMM_DISABLE = "disabled"
	COMM_START = "start"
	COMM_STOP = "stop"
	COMM_SET = "set"
	COMM_STEER = "steer"
	COMM_STEER2 = "steer2"
	COMM_STEER3 = "steer3"

class CommandCreate(object):
	def create(type_, value = None):
		if type_ == CommandTypes.COMM_SET:
			data = {"type": type_, "value" : value}
			return json.dumps(data)
		else:
			data = {"type": type_}
			return json.dumps(data)

class CommandParse(object):
	def parse(data):
		decode_data = data.decode('UTF-8')
		return json.loads(decode_data)

class CommandPub(object):
	def __init__(self, ip='127.0.0.1'):
		self.pub = mc.MQTTControlPub(ip)
	def send_enable(self):
		json_str = CommandCreate.create(CommandTypes.COMM_ENABLE, None)
		self.pub.send(json_str)
	def send_disable(self):
		json_str = CommandCreate.create(CommandTypes.COMM_DISABLE, None)
		self.pub.send(json_str)
	def send_start(self):
		json_str = CommandCreate.create(CommandTypes.COMM_START, None)
		self.pub.send(json_str)
	def send_stop(self):
		json_str = CommandCreate.create(CommandTypes.COMM_STOP, None)
		self.pub.send(json_str)
	def send_set(self, speed, steer):
		json_str = CommandCreate.create(CommandTypes.COMM_SET, [speed, steer])
		self.pub.send(json_str)
	def send_steer(self):
		json_str = CommandCreate.create(CommandTypes.COMM_STEER, None)
		self.pub.send(json_str)
	def send_steer2(self):
		json_str = CommandCreate.create(CommandTypes.COMM_STEER2, None)
		self.pub.send(json_str)
	def send_steer3(self):
		json_str = CommandCreate.create(CommandTypes.COMM_STEER3, None)
		self.pub.send(json_str)
    
class CommandSub(object):
	def __init__(self, ip='127.0.0.1'):
		self.sub = mc.MQTTControlSub(on_msg=self.on_msg,ip=ip) 
		self.on_start = None
		self.on_stop = None
		self.on_enable = None
		self.on_disable = None
		self.on_set = None
		self.on_steer = None
		self.on_steer2 = None
		self.on_steer3 = None
    
	def on_msg(self, data):
		dictionary = CommandParse.parse(data)
		if dictionary['type'] == CommandTypes.COMM_ENABLE:
			if self.on_enable:
				self.on_enable()
		if dictionary['type'] == CommandTypes.COMM_DISABLE:
			if self.on_disable:
				self.on_disable()
		if dictionary['type'] == CommandTypes.COMM_START:
			if self.on_start:
				self.on_start()
		if dictionary['type'] == CommandTypes.COMM_STOP:
			if self.on_stop:
				self.on_stop()
		if dictionary['type'] == CommandTypes.COMM_STEER:
			if self.on_steer:
				self.on_steer()
		if dictionary['type'] == CommandTypes.COMM_STEER2:
			if self.on_steer2:
				self.on_steer2()
		if dictionary['type'] == CommandTypes.COMM_STEER3:
			if self.on_steer3:
				self.on_steer3()

		if dictionary['type'] == CommandTypes.COMM_SET:
			if self.on_set:
				speed, angle = dictionary['value']
				load = {}
				load["speed"] = speed
				load["steer"] = angle
				self.on_set(load)
if __name__ == '__main__':
	import time
	sub = CommandSub(ip = '127.0.0.1')
	def set_handler(load):
		print('I received {}'.format(load))
	def start_handler():
		print('i received start')
	def stop_handler():
		print('i received stop')
	def steer_handler():
		print('I received STEER')
	# NEW START
	def steer2_handler():
		print('I received STEER2')
	# NEW END
	sub.on_set = set_handler
	sub.on_start = start_handler
	sub.on_stop = stop_handler
	sub.on_steer = steer_handler
	# NEW START
	sub.on_steer2 = steer2_handler
	# NEW END

	pub = CommandPub(ip = '127.0.0.1')
	while 1:
		print('I send start')
		pub.send_start()
		time.sleep(1)
		print('I send stop')
		pub.send_stop()
		time.sleep(1)
		print('I send enabled')
		pub.send_enable()
		time.sleep(1)
		print('I send disabled')
		pub.send_disable()
		time.sleep(1)
		print('I send set 5, 7')
		pub.send_set(5, 7)
		time.sleep(1)
		pub.send_steer()
		print('I send STEER')
		# NEW START
		pub.send_steer2()
		print('I send STEER2')
		# NEW END

		time.sleep(1)

