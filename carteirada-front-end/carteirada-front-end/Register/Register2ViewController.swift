//
//  Register2ViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 22/09/22.
//

import UIKit

class Register2ViewController: UIViewController {

    @IBOutlet weak var registerButtonEdit: UIButton!
    @IBOutlet weak var emailTF: UITextField!
    @IBOutlet weak var userTF: UITextField!
    @IBOutlet weak var pwTF: UITextField!
    @IBOutlet weak var confirmPWTF: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupButton()
    }
    
    
    
    func setupButton() {
        registerButtonEdit.layer.cornerRadius = 20
        registerButtonEdit.layer.shadowColor = UIColor.black.cgColor
        registerButtonEdit.layer.shadowOffset = CGSize(width: 0.0, height: 4.0)
        registerButtonEdit.layer.shadowRadius = 4.0
        registerButtonEdit.layer.shadowOpacity = 0.5
        registerButtonEdit.layer.masksToBounds = false
    }

}
